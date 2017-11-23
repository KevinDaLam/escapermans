#ifndef BITMAPS_H
#define BITMAPS_H

#include "GLCD.h"

#define DG	Olive
#define	LG	Green
#define WH	White
#define BL	Black
#define	YL	Yellow

#define ESCAPERMAN_X	56
#define ESCAPERMAN_Y	28

const unsigned short ESCAPERMAN_BITMAP_R[] = {
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,BL,BL,BL,BL,BL,BL,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,BL,BL,BL,BL,BL,BL,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,BL,BL,DG,DG,DG,DG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,BL,BL,YL,YL,BL,BL,YL,YL,BL,BL,DG,DG,BL,BL,WH,WH,WH,WH,WH,WH,WH,
	WH,BL,BL,DG,DG,DG,DG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,BL,BL,YL,YL,BL,BL,YL,YL,BL,BL,DG,DG,BL,BL,WH,WH,WH,WH,WH,WH,WH,
	WH,BL,BL,BL,BL,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,BL,BL,YL,YL,YL,YL,YL,YL,BL,BL,DG,DG,DG,DG,BL,BL,WH,WH,WH,WH,WH,
	WH,BL,BL,BL,BL,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,BL,BL,YL,YL,YL,YL,YL,YL,BL,BL,DG,DG,DG,DG,BL,BL,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,BL,BL,YL,YL,BL,BL,YL,YL,BL,BL,DG,DG,DG,DG,DG,DG,BL,BL,WH,WH,WH,
	WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,BL,BL,YL,YL,BL,BL,YL,YL,BL,BL,DG,DG,DG,DG,DG,DG,BL,BL,WH,WH,WH,
	WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,BL,BL,YL,YL,YL,YL,YL,YL,BL,BL,DG,DG,DG,DG,DG,DG,DG,DG,BL,BL,WH,
	WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,BL,BL,YL,YL,YL,YL,YL,YL,BL,BL,DG,DG,DG,DG,DG,DG,DG,DG,BL,BL,WH,
	WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,YL,YL,YL,YL,YL,YL,YL,YL,BL,BL,DG,DG,DG,DG,DG,DG,BL,BL,WH,WH,WH,
	WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,YL,YL,YL,YL,YL,YL,YL,YL,BL,BL,DG,DG,DG,DG,DG,DG,BL,BL,WH,WH,WH,
	WH,BL,BL,BL,BL,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,DG,DG,DG,DG,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,DG,DG,DG,DG,BL,BL,WH,WH,WH,WH,WH,
	WH,BL,BL,BL,BL,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,DG,DG,DG,DG,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,DG,DG,DG,DG,BL,BL,WH,WH,WH,WH,WH,
	WH,BL,BL,DG,DG,DG,DG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,BL,BL,DG,DG,DG,DG,LG,LG,LG,LG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,BL,BL,WH,WH,WH,WH,WH,WH,WH,
	WH,BL,BL,DG,DG,DG,DG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,BL,BL,DG,DG,DG,DG,LG,LG,LG,LG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,BL,BL,WH,WH,WH,WH,WH,WH,WH,
	WH,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH
};

const unsigned short ESCAPERMAN_BITMAP_L[] = {
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,BL,BL,DG,DG,DG,DG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,BL,BL,DG,DG,DG,DG,LG,LG,LG,LG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,BL,BL,WH,WH,WH,WH,WH,WH,WH,
	WH,BL,BL,DG,DG,DG,DG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,BL,BL,DG,DG,DG,DG,LG,LG,LG,LG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,DG,BL,BL,WH,WH,WH,WH,WH,WH,WH,
	WH,BL,BL,BL,BL,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,DG,DG,DG,DG,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,DG,DG,DG,DG,BL,BL,WH,WH,WH,WH,WH,
	WH,BL,BL,BL,BL,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,DG,DG,DG,DG,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,DG,DG,DG,DG,BL,BL,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,YL,YL,YL,YL,YL,YL,YL,YL,BL,BL,DG,DG,DG,DG,DG,DG,BL,BL,WH,WH,WH,
	WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,YL,YL,YL,YL,YL,YL,YL,YL,BL,BL,DG,DG,DG,DG,DG,DG,BL,BL,WH,WH,WH,
	WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,BL,BL,YL,YL,YL,YL,YL,YL,BL,BL,DG,DG,DG,DG,DG,DG,DG,DG,BL,BL,WH,
	WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,BL,BL,YL,YL,YL,YL,YL,YL,BL,BL,DG,DG,DG,DG,DG,DG,DG,DG,BL,BL,WH,
	WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,BL,BL,YL,YL,BL,BL,YL,YL,BL,BL,DG,DG,DG,DG,DG,DG,BL,BL,WH,WH,WH,
	WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,BL,BL,YL,YL,BL,BL,YL,YL,BL,BL,DG,DG,DG,DG,DG,DG,BL,BL,WH,WH,WH,
	WH,BL,BL,BL,BL,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,BL,BL,YL,YL,YL,YL,YL,YL,BL,BL,DG,DG,DG,DG,BL,BL,WH,WH,WH,WH,WH,
	WH,BL,BL,BL,BL,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,BL,BL,YL,YL,YL,YL,YL,YL,BL,BL,DG,DG,DG,DG,BL,BL,WH,WH,WH,WH,WH,
	WH,BL,BL,DG,DG,DG,DG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,BL,BL,YL,YL,BL,BL,YL,YL,BL,BL,DG,DG,BL,BL,WH,WH,WH,WH,WH,WH,WH,
	WH,BL,BL,DG,DG,DG,DG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,DG,DG,BL,BL,YL,YL,BL,BL,YL,YL,BL,BL,YL,YL,BL,BL,DG,DG,BL,BL,WH,WH,WH,WH,WH,WH,WH,
	WH,BL,BL,BL,BL,BL,BL,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,BL,BL,BL,BL,BL,BL,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,DG,DG,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,BL,BL,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,LG,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,BL,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH
};

const unsigned short ESCAPERMAN_CLEAR[] = {
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,
	WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH,WH
	
};


#endif
