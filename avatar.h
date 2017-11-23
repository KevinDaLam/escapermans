#ifndef AVATAR_H
#define AVATAR_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define SCREEN_WIDTH		240
#define SCREEN_HEIGHT		300
#define AVATAR_SIZE			24

struct Avatar {
	uint8_t x_pos;
	struct Platform *platform;
	
	bool falling;
	uint16_t y_pos_falling;
	
	uint8_t size;
};

struct Avatar* avatar_init(void);

uint8_t avatar_get_y(struct Avatar *avatar);

void avatar_bind_platform(struct Avatar *avatar, struct Platform *plat);

bool avatar_check_hole(struct Avatar *avatar);

void avatar_start_fall(struct Avatar *avatar, struct Platform *next_plat);

void avatar_fall_decrement_y(struct Avatar *avatar, uint8_t fall_step);

#endif
