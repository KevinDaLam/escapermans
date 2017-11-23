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
#define SCREEN_HEIGHT			300
#define AVATAR_SPEED			2
#define TERMINAL_VELOCITY		4

uint32_t score_count = 0;
uint8_t n_lives = 3;
uint8_t n_powerups = 3;
uint8_t current_platform = MAX_N_PLATFORMS/2;

struct Avatar *avatar1;
bool avatar_orient_r = true;
uint8_t fall_step = 1;

struct Platform *platforms[MAX_N_PLATFORMS];
uint8_t platform_speed = 1;

OS_MUT avatar_mut;


bool cmd_powerup = false;

__task void update_avatar(void){
	
	uint8_t command;

	while(true){
  	
		os_tsk_pass();
		
		os_mut_wait(&avatar_mut, 0xffff);
		
		command = poll_joystick_direction();

		if (command == CMD_MOVE_LEFT){
			avatar1->x_pos = avatar1->x_pos <= 0 ? 0 : (avatar1->x_pos >= AVATAR_SPEED ? avatar1->x_pos - AVATAR_SPEED : 0);
			avatar_orient_r = false;
		}
		else if (command == CMD_MOVE_RIGHT){
			avatar1->x_pos = avatar1->x_pos >= SCREEN_WIDTH - avatar1->size ? SCREEN_WIDTH - avatar1->size  : avatar1->x_pos + AVATAR_SPEED;
			avatar_orient_r = true;
		}

		
		if (avatar1->falling){
			
			GLCD_clear_avatar(avatar1);
			
			if(avatar1->y_pos_falling > avatar1->platform->y_pos){
				avatar_fall_decrement_y(avatar1, fall_step);
				fall_step = fall_step == TERMINAL_VELOCITY ? TERMINAL_VELOCITY : fall_step + 1;
			}
			else{
				avatar1->falling = false;
				score_count++;
				if (!avatar_check_hole(avatar1)){
					fall_step = 0;
				}
			}
		}
		else{
			if(avatar_check_hole(avatar1)){
				current_platform = (current_platform + 1) % MAX_N_PLATFORMS;
				avatar_start_fall(avatar1, platforms[current_platform]);
			}
		}
		
		os_mut_release(&avatar_mut);
		
	}
}

__task void update_platforms(void){
	
	uint8_t highest_platform = 0;
	
	while(true){
		
		int i;
		
		os_tsk_pass();
		
		os_mut_wait(&avatar_mut, 0xffff);
		
		for(i = 0; i < MAX_N_PLATFORMS; i++){
			/*
			if((platforms[i == 0 ? MAX_N_PLATFORMS-1:i-1]->y_pos >= platforms[i]->y_pos + PLATFORM_INTERVAL_SIZE) || i != highest_platform){
				platform_refresh(platforms[i], platform_speed);
			}
			*/
		
			if (platforms[highest_platform]->y_pos >= SCREEN_HEIGHT){
				platform_recycle(platforms[highest_platform]);
				highest_platform = (highest_platform + 1) % MAX_N_PLATFORMS;
			}
		
			if (cmd_powerup && n_powerups){
				printf("HELLO");
				platform_dig(avatar1->platform, avatar1->x_pos);
				cmd_powerup = false;
				n_powerups--;
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
		
		for (j = 0; j < 100000; j++);
		
		for(i = 0; i < MAX_N_PLATFORMS; i++){
			platform_refresh(platforms[i], platform_speed);
			GLCD_update_platform(platforms[i], platform_speed);
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

void EINT3_IRQHandler(void){
	cmd_powerup = true;
	LPC_GPIOINT->IO2IntClr |= (1<<10);
}

void platforms_setup(void){
	
	int i;
	
	for(i = 0; i < MAX_N_PLATFORMS; i++){
		platforms[i] = platform_spawn();
		platforms[i]->y_pos = PLATFORM_INTERVAL_SIZE*(MAX_N_PLATFORMS - 1 - i);
	}

}

void avatar_setup(void){
	avatar1 = avatar_init();
	
	avatar1->platform = platforms[current_platform];
	avatar1->x_pos = SCREEN_WIDTH/2;
}

int main(void){
	
	platforms_setup();
	avatar_setup();
	
	//Powerup Button Initialization
	LPC_PINCON->PINSEL4 &= ~(3 << 20);
	LPC_GPIO2->FIODIR &= ~(1<<10);
	LPC_GPIOINT->IO2IntEnF |= (1<<10);
  
	//LED Initialization
	LPC_GPIO1->FIODIR |= 0xB0000000;
	LPC_GPIO2->FIODIR |= 0x7C;
	
	LPC_GPIO1->FIOCLR |= 0xFF000000;
	LPC_GPIO2->FIOCLR |= 0xFF;
	
	//Display Initialization
	GLCD_Init();
	GLCD_Clear(White);
	GLCD_SetBackColor(White);
	
	
	
	printf("STARTING GAME\n");
	
	NVIC_EnableIRQ( EINT3_IRQn );
	

	os_sys_init(start_tasks);
  
}
