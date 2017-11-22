#include "led.h"
#include "peripherals.h"

uint8_t poll_joystick_direction(){
	
	GPIO1_state = LPC_GPIO1->FIOPIN;
  	
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
