#ifndef AVATAR_H
#define AVATAR_H

#include <stdint.h>

struct Avatar {
  uint8_t x_pos;
  struct Platform *platform;
};

uint8_t avatar_get_y(struct Avatar *avatar);

void avatar_bind_platform(struct Avatar *avatar, struct Platform *plat);

void avatar_fall(struct Avatar *avatar);

#endif