#include <stdlib.h>
#include "platform.h"
#include "GLCD.h"

struct Platform *platform_generate(void) {
    int i;
    struct Platform *platform = malloc(sizeof(struct Platform));

    platform->y_pos = 0;
  
    //Initialize Holes
    for (i = 0; i < HOLE_MAX_N-1; i++) {
        platform->holes[i].size = HOLE_MIN_SIZE + rand()%(HOLE_MAX_SIZE - HOLE_MIN_SIZE);
        platform->holes[i].loc = rand()%(PLATFORM_WIDTH - HOLE_MAX_SIZE);
    }
    platform->holes[HOLE_MAX_N].size = 0;
    platform->holes[HOLE_MAX_N].loc = 0;
  
    return platform;
}

void platform_update_loc(struct Platform *platform, uint8_t y) {
    platform->y_pos += y;
}

void platform_dig(struct Platform *platform, uint8_t xloc) {
    platform->holes[HOLE_MAX_N - 1].size = DIG_HOLE_SIZE;
    platform->holes[HOLE_MAX_N - 1].loc = xloc;
}

void platform_holify(struct Platform *platform, unsigned short *platform_bitmap, unsigned short bitmap_w) {
    int i;

    for (i = 0; i < HOLE_MAX_N; i++) {
        printf("\n\ni : %d\n", i);
        printf("Platform hole size: %d\n", platform->holes[i].size);
        // Only dig holes that have a non-zero size
        if (platform->holes[i].size > 0) {
            int pix = platform->holes[i].loc, pix_w = 0, pix_h = 0;
            
            while (pix_w < DIG_HOLE_SIZE && pix_h < PLATFORM_HEIGHT) {
                platform_bitmap[pix] = White;
                printf("x");
                pix_w++;
                pix++;
                if (pix_w == DIG_HOLE_SIZE - 1) {
                    pix_h++;
                    pix_w = 0;
                    pix = pix - DIG_HOLE_SIZE - 1 + bitmap_w;
                }
            }
        }
        printf("\n");
    }
}

void platform_deholify(struct Platform *platform, unsigned short *platform_bitmap, unsigned short bitmap_w) {
    int i;

    for (i = 0; i < HOLE_MAX_N; i++) {
        int pix = platform->holes[i].loc, pix_w = 0, pix_h = 0;
            
        while (pix_w < DIG_HOLE_SIZE || pix_h < PLATFORM_HEIGHT) {
            platform_bitmap[pix] = PLATFORM_COLOR;
            pix_w++;
            if (pix_w == DIG_HOLE_SIZE - 1) {
                pix_h++;
                pix_w = platform->holes[i].loc;
                pix = pix_w + bitmap_w;
            }
        }
    }    
}