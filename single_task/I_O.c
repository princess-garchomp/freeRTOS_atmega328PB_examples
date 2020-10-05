#include <avr/io.h>
#include "I_O.h"

#define MASK(X) (1ul<<(X))

/*
 corresponding arduino pins:

	BUTTONS
	A2
	FIRST
A5
A4
A3
*/

#define FIRST_RGB_LED_RED_SHIFT (PC3)
#define FIRST_RGB_LED_GREEN_SHIFT (PC4)
#define FIRST_RGB_LED_BLUE_SHIFT (PC5)



#define BUTTON_SHIFT (PC2)




static void first_rgb_led_red_on();
static void first_rgb_led_red_off();
static void first_rgb_led_green_on();
static void first_rgb_led_green_off();
static void first_rgb_led_blue_on();
static void first_rgb_led_blue_off();



void all_I_O_config(){
	first_rgb_led_config();
	button_config();
}
void first_rgb_led_config(){
	DDRC |= MASK(FIRST_RGB_LED_RED_SHIFT)|MASK(FIRST_RGB_LED_GREEN_SHIFT)|MASK(FIRST_RGB_LED_BLUE_SHIFT);
	first_rgb_led_color(WHITE);
}

void button_config(){
	DDRC &= ~(MASK(BUTTON_SHIFT));
	PORTC|= MASK(BUTTON_SHIFT);
}


void first_rgb_led_color(rgb_led_color color){
	switch(color){
		case(WHITE):
			first_rgb_led_red_off();
			first_rgb_led_green_off();
			first_rgb_led_blue_off();
		break;		
		case(BLUE):
			first_rgb_led_red_off();
			first_rgb_led_green_off();
			first_rgb_led_blue_on();
		break;		
		case(GREEN):
			first_rgb_led_red_off();
			first_rgb_led_green_on();
			first_rgb_led_blue_off();
		break;		
		case(CYAN):
			first_rgb_led_red_off();
			first_rgb_led_green_on();
			first_rgb_led_blue_on();
		break;		
		case(RED):
			first_rgb_led_red_on();
			first_rgb_led_green_off();
			first_rgb_led_blue_off();
		break;
		case(MAGENTA):
			first_rgb_led_red_on();
			first_rgb_led_green_off();
			first_rgb_led_blue_on();
		break;		
		case(YELLOW):
			first_rgb_led_red_on();
			first_rgb_led_green_on();
			first_rgb_led_blue_off();
		break;	
		case(BLACK):
			first_rgb_led_red_on();
			first_rgb_led_green_on();
			first_rgb_led_blue_on();
		break;
	}
}


_Bool button_is_pressed(){
	return!(PINC & MASK(BUTTON_SHIFT));
}
_Bool button_is_not_pressed(){
	return!(button_is_pressed());
}

static void first_rgb_led_red_on(){
	PORTC|= MASK(FIRST_RGB_LED_RED_SHIFT);
}
static void first_rgb_led_red_off(){
	PORTC &= ~MASK(FIRST_RGB_LED_RED_SHIFT);
}
static void first_rgb_led_green_on(){
	PORTC |= MASK(FIRST_RGB_LED_GREEN_SHIFT);
}
static void first_rgb_led_green_off(){
	PORTC &= ~MASK(FIRST_RGB_LED_GREEN_SHIFT);
}
static void first_rgb_led_blue_on(){
	PORTC |= MASK(FIRST_RGB_LED_BLUE_SHIFT);
}
static void first_rgb_led_blue_off(){
	PORTC &= ~MASK(FIRST_RGB_LED_BLUE_SHIFT);
}

void toggle_led()
{
	//this toggles all of port C
	//usefull for getting the demo working
	PORTC = ~(PORTC);
}

