#ifndef PLATFORM_H
#define PLATFORM_H

#include <stdint.h>

// Platform details
#define HOLE_MAX_N          3
#define HOLE_MIN_SIZE       10
#define HOLE_MAX_SIZE       20
#define PLATFORM_WIDTH      100
#define PLATFORM_HEIGHT     2
#define PLATFORM_COLOR      Black
#define DIG_HOLE_SIZE       5
#define LCD_MAX_WIDTH       240

struct Hole {
    uint8_t size;
    uint8_t loc;
};

struct Platform {
    struct Hole holes[HOLE_MAX_N];
    uint8_t y_pos;
};

struct Platform *platform_generate(void);

void platform_update_loc(struct Platform *platform, uint8_t y);

void platform_dig(struct Platform *platform, uint8_t loc);

// Modifies a platform bitmap array and digs all holes
void platform_holify(struct Platform *platform, unsigned short *platform_bitmap, unsigned short bitmap_w);

// Modifies a platform bitmap array and restores all holes
void platform_deholify(struct Platform *platform, unsigned short *platform_bitmap, unsigned short bitmap_w);
#endif