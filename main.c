#include <RTL.h>
#include <stdbool.h>
#include <stdint.h>
#include <peripherals.h>

struct Avatar avatar1 = DEFAULT_AVATAR;


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

int main(void){
  
  os_sys_init(start_tasks);
  
}
