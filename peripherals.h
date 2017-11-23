#ifndef PERIPHERALS_H
#define PERIPHERALS_H

#include <stdint.h>
#include <lpc17xx.h>
#include "led.h"
#include "avatar.h"
#include "GLCD.h"
#include "platform.h"

#define JS_RIGHT	0x2000000
#define JS_UP		0x1000000
#define JS_DOWN		0x4000000
#define	JS_LEFT		0x800000
#define JS_PRESS	0x100000

#define CMD_MOVE_LEFT	1
#define CMD_MOVE_RIGHT	2
#define CMD_NO_MOVE		0



//Returns direction if pressed, else no move
uint8_t poll_joystick_direction(void);

void GLCD_update_avatar(struct Avatar *avatar, bool orientation_right);

void GLCD_update_platform(struct Platform *platform, int refresh_step);

void GLCD_update_lives(void);

void GLCD_clear_avatar(struct Avatar *avatar);

#endif
