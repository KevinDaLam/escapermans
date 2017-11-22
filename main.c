#include <RTL.h>
#include <stdbool.h>
#include <stdint.h>
#include <peripherals.h>

uint8_t n_lives = 3;
uint8_t n_powerups = 3;

struct Avatar avatar1 = DEFAULT_AVATAR;

bool cmd_powerup = false;

__task void update_avatar(void){
  
  uint8_t command;
  
  while(true){
  	
  	os_tsk_pass();
  	
  	command = poll_joystick_direction();
  	
  	if (command == CMD_MOVE_LEFT){
  		avatar1->x_pos--
  	}
  	else if (command == CMD_MOVE_RIGHT){
		avatar1->x_pos++
  	}
  	
  	if (avatar_check_hole(avatar1)){
  		avatar_start_fall(avatar1);
  	}
  	
  	if (avatar1->falling){
  		
  		if(avatar->y_pos_falling > avatar->platform->y_pos){
  			avatar_fall_decrement_y(avatar1);
  		}
  		else{
  			avatar1->falling = false;
  		}
  		
  	}
  	
  }
  
}

__task void update_platforms(void){
  
  while(true){
  	
  	os_tsk_pass();
  	
  	if (cmd_powerup && n_powerups){
  		platform_dig(avatar1->platform, avatar1->x_pos);
  		cmd_powerup = false;
  	}
	
  }
}

__task void update_display(void){
  
  while(true){
  	
  	os_tsk_pass();
  	
  }
  
}

__task void start_tasks(void){
	
	os_tsk_create(update_avatar, 1);
	os_tsk_create(update_platforms, 1);
	os_tsk_create(update_display, 1);
	
	os_tsk_delete_self();
	
}

void EINT3_IRQHandler(void){
	cmd_powerup = true;
	LPC_GPIOINT->IO2IntClr |= (1<<10);
}

int main(void){
  
  LPC_PINCON->PINSEL4 &= ~(3 << 20);
  LPC_GPIO2->FIODIR &= ~(1<<10);
  LPC_GPIOINT->IO2IntEnF |= (1<<10);
  
  NVIC_EnableIRQ(ENT3_IRQn);
  
  os_sys_init(start_tasks);
  
}
