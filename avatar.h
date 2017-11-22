#ifndef AVATAR_H
#define AVATAR_H

#include <stdint.h>
#include <stdbool.h>

#define FALLING_INTERVAL	1
#define SCREEN_WIDTH		240
#define SCREEN_HEIGHT		300

const struct Avatar DEFAULT_AVATAR = {
	SCREEN_WIDTH/2, NULL, SCREEN_HEIGHT/2, false		
};

struct Avatar {
	uint8_t x_pos;
	struct Platform *platform;
	
	bool falling;
	uint8_t y_pos_falling;
	
	uint8_t size;https://github.com/KevinDaLam/escapermans/invitations
};

uint8_t avatar_get_y(struct Avatar *avatar);

void avatar_bind_platform(struct Avatar *avatar, struct Platform *plat);

bool avatar_check_hole(struct Avatar *avatar);

void avatar_start_fall(struct Avatar *avatar, struct Platform *next_plat);

void avatar_fall_decrement_y();

#endif
