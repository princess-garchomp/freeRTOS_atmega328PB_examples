#ifndef I_O_H
#define I_O_H

typedef enum {WHITE, BLUE, GREEN, CYAN, RED, MAGENTA, YELLOW, BLACK}
rgb_led_color;

//this configs the entier driver if there is no need to use the pins for other shit
void all_I_O_config();

//configing first and second seperately so if i need the pins they are avalible for other drivers


void first_rgb_led_config();

void button_config();

void first_rgb_led_color(rgb_led_color color);

void toggle_led();


_Bool button_is_pressed();
_Bool button_is_not_pressed();

#endif