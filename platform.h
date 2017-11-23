#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdint.h>
#include <stdbool.h>

// Platform details
#define HOLE_MAX_N          3
#define HOLE_MIN_SIZE       30
#define HOLE_MAX_SIZE       50
#define DIG_HOLE_SIZE		32
#define CHARACTER_WIDTH		28

#define PLATFORM_WIDTH      240
#define PLATFORM_HEIGHT     4
#define PLATFORM_MAX_N		5
#define PLATFORM_DIST		40
#define PLATFORM_COLOR      Red
#define BACKGROUND_COLOR	White
#define REFRESH_STEP		1

#define LCD_MAX_WIDTH       240
#define LCD_MAX_HEIGHT		320
#define LCD_PLAT_MAX_HEIGHT	290

struct Hole {
    uint8_t size;
    uint8_t loc;
};

struct Platform {
    struct Hole holes[HOLE_MAX_N];
    uint16_t y_pos;
};

void platform_init(struct Platform *platform);

struct Platform *platform_spawn(void);

void platform_bitmap_init(void);

void platform_bitmap_fill(void);

void platform_recycle(struct Platform *platform);

// Moves platform up by <y> pixels
void platform_refresh(struct Platform *platform);

void platform_dig(struct Platform *platform, uint8_t loc);

// Adds holes to the platform on the LCD
void platform_holify(struct Platform *platform);

// Displays platform to LCD screen
void platform_display(struct Platform *platform);
#endif