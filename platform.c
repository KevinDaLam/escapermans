#include <stdlib.h>
#include "platform.h"
#include "GLCD.h"

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
	else if (platform->holes[0].loc > platform->holes[1].loc) {
		// Sort initial holes by location; makes printing easier
		int temp = platform->holes[1].loc;
		platform->holes[1].loc = platform->holes[0].loc;
		platform->holes[0].loc = temp;
	}	
}

struct Platform *platform_spawn(void) {
    struct Platform *platform = malloc(sizeof(struct Platform));

	platform_init(platform);
	
    return platform;
}

void platform_refresh(struct Platform *platform, int refresh_step) {
	platform->y_pos += refresh_step;
}


void platform_dig(struct Platform *platform, uint8_t xloc) {
	int i, j;
	
    platform->holes[HOLE_MAX_N - 1].size = DIG_HOLE_SIZE;
    platform->holes[HOLE_MAX_N - 1].loc = xloc;
	
	// Bubble sort holes in order of location; makes printing easier
	/*
	for (i = 0; i < HOLE_MAX_N - 1; i++) {
		for (j = 0; j < HOLE_MAX_N - i - 1; j++) {
			if (platform->holes[j].loc > platform->holes[j+1].loc) {
				int temp = platform->holes[j+1].loc;
				platform->holes[j+1].loc = platform->holes[j].loc;
				platform->holes[j].loc = temp;
			}
		}
	}	
	*/
}

void platform_recycle(struct Platform *platform) {
	int i;
	// Erase platform on the LCD
	GLCD_SetTextColor(BACKGROUND_COLOR);	
	for (i = 0; i < PLATFORM_WIDTH; i++) {
		GLCD_PutPixel(LCD_PLAT_MAX_HEIGHT, i);
	}
	// Reset platform
	platform_init(platform);
}
