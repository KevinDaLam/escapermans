#include "peripherals.h"
#include "bitmaps.h"

uint8_t poll_joystick_direction(void){
	
	uint32_t GPIO1_state = LPC_GPIO1->FIOPIN;
  	
	if (~(GPIO1_state) & JS_LEFT){
		return CMD_MOVE_LEFT;
	}
	else if (~(GPIO1_state) & JS_RIGHT){
		return CMD_MOVE_RIGHT;
	}
	else{
		return CMD_NO_MOVE;
	}
	
}

void GLCD_update_avatar(struct Avatar *avatar, bool orientation_right){
	
	if (avatar->falling){

		if(orientation_right){
			GLCD_Bitmap(avatar->y_pos_falling + 2, avatar->x_pos, ESCAPERMAN_X, ESCAPERMAN_Y, (unsigned char*)ESCAPERMAN_BITMAP_R);
		}
		else{
			GLCD_Bitmap(avatar->y_pos_falling + 2, avatar->x_pos, ESCAPERMAN_X, ESCAPERMAN_Y, (unsigned char*)ESCAPERMAN_BITMAP_L);
		}
	}
	else{
		if(orientation_right){
			GLCD_Bitmap(avatar->platform->y_pos + 2, avatar->x_pos, ESCAPERMAN_X, ESCAPERMAN_Y, (unsigned char*)ESCAPERMAN_BITMAP_R);
		}
		else{
			GLCD_Bitmap(avatar->platform->y_pos + 2, avatar->x_pos, ESCAPERMAN_X, ESCAPERMAN_Y, (unsigned char*)ESCAPERMAN_BITMAP_L);
		}
	}
	
}

void GLCD_update_platform(struct Platform *platform, int refresh_step) {
	int i = 0, x_loc = 0, x_end = -1;
	int y_loc = platform->y_pos - refresh_step;
	int hole_locs[HOLE_MAX_N + 1];

	// Parse for hole locations
	for (i = 0; i < HOLE_MAX_N; i++) {
		if (platform->holes[i].size > 0)
			hole_locs[i] = platform->holes[i].loc;
		else
			hole_locs[i] = -1;
	}
	// Last 'hole' is the end of the platform
	hole_locs[HOLE_MAX_N] = PLATFORM_WIDTH;
	
	//printf("\nPlatform specs:: y_pos: %d, hole sizes: %d %d %d, hole locs: %d %d %d %d\n", platform->y_pos, platform->holes[0].size, platform->holes[1].size, platform->holes[2].size, 
	//																									 hole_locs[0], hole_locs[1], hole_locs[2], hole_locs[3]);	
	
	// Setting color to erase platform
	GLCD_SetTextColor(BACKGROUND_COLOR);	
	for (i = 0; i < HOLE_MAX_N + 1; i++) {
		// Check if hole is present
		if (hole_locs[i] > -1) {
			x_loc = hole_locs[i];
			while (x_loc > x_end) {
				// We use reversed x-y axis for the LCD
				GLCD_PutPixel(y_loc, x_loc);
				x_loc--;
			}
			x_end = hole_locs[i] + HOLE_MAX_SIZE;
		}
	}
	
	y_loc += refresh_step;
	x_end = -1;
	
	// Setting color to draw platform
	GLCD_SetTextColor(PLATFORM_COLOR);	
	for (i = 0; i < HOLE_MAX_N + 1; i++) {
		// Check if hole is present
		if (hole_locs[i] > -1) {
			x_loc = hole_locs[i];			
			while (x_loc > x_end) {
				// We use reversed x-y axis for the LCD
				GLCD_PutPixel(y_loc, x_loc);
				//printf("\n X_LOC: %d\n", x_loc);
				x_loc--;
			}
			x_end = hole_locs[i] + HOLE_MAX_SIZE;
			//printf("\n X_END: %d\n", x_end);
		}
	}		
}

void GLCD_clear_avatar(struct Avatar *avatar){
	GLCD_Bitmap(avatar->y_pos_falling, avatar->x_pos, ESCAPERMAN_X+2, ESCAPERMAN_Y, (unsigned char*)ESCAPERMAN_CLEAR);
}