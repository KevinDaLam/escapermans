#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdint.h>

#define MAX_N_HOLES 3

struct Hole {
  uint8_t size;
  uint8_t loc;
};

struct Platform {
  struct Hole holes[MAX_N_HOLES];
  uint8_t y_pos;
};

struct Platform *new_platform(void);

void update_loc_platform(struct Platform *platform, uint8_t y_pos);

void dig_platform(struct Platform *platform, uint8_t loc);


#endif