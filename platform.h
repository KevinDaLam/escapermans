#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdint.h>

// Platform details
#define HOLE_MAX_N          3
#define HOLE_MIN_SIZE       30
#define HOLE_MAX_SIZE       50
#define DIG_HOLE_SIZE       30

#define PLATFORM_WIDTH      240
#define PLATFORM_HEIGHT     2
#define PLATFORM_MAX_N		5
#define PLATFORM_DIST		40
#define PLATFORM_COLOR      Black
#define BACKGROUND_COLOR	White

#define LCD_MAX_WIDTH       240
#define LCD_MAX_HEIGHT		320
#define LCD_PLAT_MAX_HEIGHT	300

struct Hole {
    uint8_t size;
    uint8_t loc;
};

struct Platform {
    struct Hole holes[HOLE_MAX_N];
    uint16_t y_pos;
};

struct Platform *platform_spawn(void);

// Moves platform up by <y> pixels
void platform_refresh(struct Platform *platform, int refresh_step);

void platform_dig(struct Platform *platform, uint8_t loc);

// Adds holes to the platform on the LCD
void platform_holify(struct Platform *platform, int hole_n);

void platform_recycle(struct Platform *platform);


#endif