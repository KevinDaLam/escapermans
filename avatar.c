#include <stdbool.h>
#include <stdint.h>

#include "avatar.h"
#include "platform.h"

struct Avatar *avatar_init(void){
	
	struct Avatar *avatar = malloc(sizeof(struct Avatar));
	
	avatar->x_pos = SCREEN_WIDTH/2;
	avatar->platform = NULL;
	avatar->falling = false;
	avatar->y_pos_falling = SCREEN_HEIGHT/2;
	avatar->size = AVATAR_SIZE;
	
	return avatar;
}

void avatar_bind_platform(struct Avatar *avatar, struct Platform *plat){
	avatar->platform = plat;
}

bool avatar_check_hole(struct Avatar *avatar){
	
	int i;

	for (i = 0; i < HOLE_MAX_N; i++){
		
		uint8_t hole_loc = avatar->platform->holes[i].loc;
		uint8_t hole_size = avatar->platform->holes[i].size;
		
		//Checks if avatar x dimensions is within hole dimensions
		if ((avatar->x_pos >= hole_loc) && (avatar->x_pos + avatar->size <= hole_loc + hole_size)){
			return true;
		}
			
	}
	
	return false;
}

void avatar_start_fall(struct Avatar *avatar, struct Platform *next_plat){
	avatar->y_pos_falling = avatar->platform->y_pos;
	avatar->platform = next_plat;
	avatar->falling = true;
}

void avatar_fall_decrement_y(struct Avatar *avatar, uint8_t fall_step){
	avatar->y_pos_falling -= fall_step;
}
