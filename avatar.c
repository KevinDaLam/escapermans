#include "avatar.h"
#include "platform.h"

uint8_t avatar_get_y(struct Avatar *avatar){
	return avatar->platform->y_pos;
}

void avatar_bind_platform(struct Avatar *avatar, struct Platform *plat){
	avatar->platform = plat;
}

void avatar_start_fall(struct Avatar *avatar, struct Platform *next_plat){
	y_pos_falling = avatar->platform->y_pos
	avatar->platform = next_plat;
	falling = true;
}

void avatar_fall_decrement_y(struct Avatar *avatar){
	avatar->y_pos_falling -= FALLING_INTERVAL;
}
