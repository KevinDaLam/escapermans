#include <stdlib.h>
#include "platform.h"
#include "GLCD.h"

unsigned short platform_bitmap[PLATFORM_WIDTH] = {0};
unsigned short platform_bitmap_eraser[PLATFORM_WIDTH] = {0};

void platform_bitmap_init(void) {
	int i;
	for (i = 0; i < PLATFORM_WIDTH; i++) {
		platform_bitmap[i] = PLATFORM_COLOR;
		platform_bitmap_eraser[i] = BACKGROUND_COLOR;
	}
}

void platform_bitmap_fill(void) {
	int i;
	for (i = 0; i < PLATFORM_WIDTH; i++) {
		platform_bitmap[i] = PLATFORM_COLOR;
	}
}

void platform_bitmap_holify(struct Platform *platform) {
    int i, hole_size, pix, pix_w = 0;

	for (i = 0; i < HOLE_MAX_N; i++) {
		hole_size = platform->holes[i].size;
		if (hole_size > 0) {
			// LCD coordinates are transposed!
			pix = platform->holes[i].loc;
			while (pix_w < hole_size) {
				platform_bitmap[PLATFORM_WIDTH - pix] = BACKGROUND_COLOR;
				pix++;
				pix_w++;
			}
			pix_w = 0;
		}
	}
}

void platform_display(struct Platform *platform) {
	platform_bitmap_fill();
	platform_bitmap_holify(platform);
	GLCD_Bitmap(platform->y_pos, 0, 1, PLATFORM_WIDTH, (unsigned char*)platform_bitmap);
	//for (i = 0; i < 65000; i++);
	GLCD_Bitmap(platform->y_pos - REFRESH_STEP*PLATFORM_HEIGHT, 0, 1, PLATFORM_WIDTH, (unsigned char*)platform_bitmap_eraser);
}

void platform_init(struct Platform *platform) {
	int i;
    platform->y_pos = 0;
  
    //Initialize Holes
    for (i = 0; i < HOLE_MAX_N-1; i++) {
        platform->holes[i].size = HOLE_MIN_SIZE + rand()%(HOLE_MAX_SIZE - HOLE_MIN_SIZE);
        platform->holes[i].loc = rand()%(PLATFORM_WIDTH - HOLE_MAX_SIZE);
    }
    platform->holes[HOLE_MAX_N - 1].size = 0;
    platform->holes[HOLE_MAX_N - 1].loc = 0;
	
	//printf("\nPlatform Unsorted Specs:: y-pos: %d, hole sizes: %d %d %d, hole loc: %d %d %d\n", platform->y_pos, platform->holes[0].size, platform->holes[1].size, platform->holes[2].size, 
	//																		  platform->holes[0].loc, platform->holes[1].loc, platform->holes[2].loc);	
	
	// Remove hole collisions
	if ((platform->holes[0].loc > platform->holes[1].loc) && (platform->holes[0].loc < platform->holes[1].loc + platform->holes[1].size)
		|| (platform->holes[1].loc > platform->holes[0].loc) && (platform->holes[1].loc < platform->holes[0].loc + platform->holes[0].size)) {
		platform->holes[1].size = 0;
	}
}

struct Platform *platform_spawn(void) {
    struct Platform *platform = malloc(sizeof(struct Platform));
	platform_init(platform);
    return platform;
}

void platform_refresh(struct Platform *platform) {
	platform->y_pos += REFRESH_STEP;
}

void platform_dig(struct Platform *platform, uint8_t xloc) {
    platform->holes[HOLE_MAX_N - 1].size = DIG_HOLE_SIZE;
    platform->holes[HOLE_MAX_N - 1].loc = xloc <= (DIG_HOLE_SIZE - CHARACTER_WIDTH)/2 ? 0 : (xloc >= LCD_MAX_WIDTH - DIG_HOLE_SIZE ? LCD_MAX_WIDTH - DIG_HOLE_SIZE : xloc-(DIG_HOLE_SIZE - CHARACTER_WIDTH)/2);
}

void platform_recycle(struct Platform *platform) {
	// Erase platform on the LCD
	GLCD_Bitmap(LCD_PLAT_MAX_HEIGHT, 0, 1, PLATFORM_WIDTH, (unsigned char*)platform_bitmap_eraser);	
	// Reset platform
	platform_init(platform);
}