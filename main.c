#include <RTL.h>
#include <lpc17xx.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "GLCD.h"
#include "peripherals.h"
#include "avatar.h"
#include "platform.h"

#define PLATFORM_INTERVAL_SIZE	60
#define MAX_N_PLATFORMS			5
#define SCREEN_HEIGHT			320
#define AVATAR_SPEED			1
#define TERMINAL_VELOCITY		4
#define DEATH_HEIGHT			265
#define platform_speed			1

uint32_t score_count = 0;
uint8_t n_lives = 3;
uint8_t n_powerups = 8;
unsigned char powerup_display = 0;

struct Avatar *avatar1;
bool avatar_orient_r = true;
uint8_t fall_step = 1;

struct Platform *platforms[MAX_N_PLATFORMS];
uint8_t current_platform = MAX_N_PLATFORMS/2;
uint8_t highest_platform = 0;

OS_MUT avatar_mut;


bool cmd_powerup = false;

//When game end conditions are met, screen changes and stays in this screen
void game_over(void){
	while(true){
		unsigned char score[100];
		snprintf(score, sizeof(score), "Score: %d", score_count);
		
		GLCD_Clear(Blue);
		GLCD_DisplayString(2, 2, 1, "GAME OVER, LOSER");
		GLCD_DisplayString(4, 2, 1, score);
		
	}
}

//Task to update avatar struct
__task void update_avatar(void){
	
	uint8_t command;

	while(true){
  	
		os_tsk_pass();
		
		os_mut_wait(&avatar_mut, 0xffff);
		
		command = poll_joystick_direction();

		//Avatar reaches top, dies
		if (avatar1->platform->y_pos >= DEATH_HEIGHT){
			game_over();
		}
		
		//Moves avatar left
		if (command == CMD_MOVE_LEFT){
			//Left wall collision check
			avatar1->x_pos = avatar1->x_pos <= 0 ? 0 : (avatar1->x_pos >= AVATAR_SPEED ? avatar1->x_pos - AVATAR_SPEED : 0);
			avatar_orient_r = false;
		}
		//Moves avatar right
		else if (command == CMD_MOVE_RIGHT){
			//Right wall collision check
			avatar1->x_pos = avatar1->x_pos >= SCREEN_WIDTH - avatar1->size ? SCREEN_WIDTH - avatar1->size  : avatar1->x_pos + AVATAR_SPEED;
			avatar_orient_r = true;
		}

		
		if (avatar1->falling){
			
			//Removes afterimage pixels of falling avatar
			GLCD_clear_avatar(avatar1);
			
			//Continues falling if it has not reached the next platform or bottom of screen
			if(avatar1->y_pos_falling > avatar1->platform->y_pos){
				avatar_fall_decrement_y(avatar1, fall_step);
				fall_step = fall_step == TERMINAL_VELOCITY ? TERMINAL_VELOCITY : fall_step + 1;
				if(avatar1->y_pos_falling <= 0){
					game_over();	
				}
			}
			else{
				avatar1->falling = false;
				score_count++;
				//Keeps falling speed if there is another hole after falling
				if (!avatar_check_hole(avatar1)){
					fall_step = 0;
				}
			}
		}
		else{

			//Starts falling if avatar is above hole
			if(avatar_check_hole(avatar1)){
				current_platform = (current_platform + 1) % MAX_N_PLATFORMS;
				if(current_platform == highest_platform){
					struct Platform *ghost_platform = platform_spawn();
					avatar_start_fall(avatar1, ghost_platform);
				}
				else{
					avatar_start_fall(avatar1, platforms[current_platform]);
				}
			}
		}
		
		os_mut_release(&avatar_mut);
		
	}
}

__task void update_platforms(void){
	
	while(true){
		
		int i;
		
		os_tsk_pass();
		
		os_mut_wait(&avatar_mut, 0xffff);
		
		for(i = 0; i < MAX_N_PLATFORMS; i++){
			
			//Moves platforms that reach the top to the bottom
			if (platforms[highest_platform]->y_pos >= SCREEN_HEIGHT){
				platform_recycle(platforms[highest_platform]);
				highest_platform = (highest_platform + 1) % MAX_N_PLATFORMS;
			}
		
			//Creates holes when powerup button is pressed
			if (cmd_powerup && n_powerups){
				printf("HELLO");
				platform_dig(avatar1->platform, avatar1->x_pos);
				cmd_powerup = false;
				n_powerups--;
				powerup_display &= ~(1 << n_powerups);
				LED_display(powerup_display);
			}
	
		}
		
		os_mut_release(&avatar_mut);
	}
}

__task void update_display(void){
	
	while(true){

		int i, j;
		
		os_tsk_pass();
		
		os_mut_wait(&avatar_mut, 0xffff);
		
		GLCD_update_avatar(avatar1, avatar_orient_r);
		
		//Delay for platform display update
		for (j = 0; j < 100000; j++);
		
		for(i = 0; i < MAX_N_PLATFORMS; i++){
			platform_refresh(platforms[i]);
			platform_display(platforms[i]);
		}
		
		os_mut_release(&avatar_mut);

	}

}

__task void start_tasks(void){
	
	os_tsk_create(update_avatar, 1);
	os_tsk_create(update_platforms, 1);
	os_tsk_create(update_display, 1);
	
	os_mut_init(&avatar_mut);
	
	os_tsk_delete_self();
	
}

//Powerup button triggers flag for tasks to check
void EINT3_IRQHandler(void){
	cmd_powerup = true;
	LPC_GPIOINT->IO2IntClr |= (1<<10);
}

void platforms_setup(void){
	
	int i;
	
	//Spawns platforms at minimum interval size apart
	for(i = 0; i < MAX_N_PLATFORMS; i++){
		platforms[i] = platform_spawn();
		platforms[i]->y_pos = PLATFORM_INTERVAL_SIZE*(MAX_N_PLATFORMS - 1 - i) + rand()%5;
	}

}

void avatar_setup(void){
	avatar1 = avatar_init();
	
	//Avatar starts on middle platform
	avatar1->platform = platforms[current_platform];
	avatar1->x_pos = SCREEN_WIDTH/2;
}

int main(void){
	
	int i;
	
	platforms_setup();
	platform_bitmap_init();
	
	avatar_setup();
	
	//Powerup Button Initialization
	LPC_PINCON->PINSEL4 &= ~(3 << 20);
	LPC_GPIO2->FIODIR &= ~(1<<10);
	LPC_GPIOINT->IO2IntEnF |= (1<<10);
  
	//LED Initialization
	LED_setup();
	for(i = 0; i < n_powerups; i++){
		powerup_display |= (1 << i);
	}
	LED_display(powerup_display);
	
	//Display Initialization
	GLCD_Init();
	GLCD_Clear(White);
	GLCD_SetBackColor(White);
	
	
	
	printf("STARTING GAME\n");
	
	NVIC_EnableIRQ( EINT3_IRQn );
	

	os_sys_init(start_tasks);
  
}
