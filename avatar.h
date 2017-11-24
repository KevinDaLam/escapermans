#ifndef AVATAR_H
#define AVATAR_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define SCREEN_WIDTH		240
#define SCREEN_HEIGHT		320
#define AVATAR_SIZE			24

struct Avatar {
	uint8_t x_pos;
	struct Platform *platform;
	
	bool falling;
	int16_t y_pos_falling;
	
	uint8_t size;
};

//Constructor for Avatar struct
struct Avatar* avatar_init(void);

//Assigns avatar to platform
void avatar_bind_platform(struct Avatar *avatar, struct Platform *plat);

//Checks if avatar is standing above hole
bool avatar_check_hole(struct Avatar *avatar);

//Initiates avatar falling
void avatar_start_fall(struct Avatar *avatar, struct Platform *next_plat);

//Decreases avatar y position when falling
void avatar_fall_decrement_y(struct Avatar *avatar, uint8_t fall_step);

#endif
