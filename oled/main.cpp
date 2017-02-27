#include <avr/io.h>

#include "Pin.h"
#include "OLED.h"

using namespace OCAPI;

int main() {
<<<<<<< HEAD
	Pin pb4(PIN_A, 4);
	pb4.setModeOut();
	pb4.setHigh();
=======
	Pin cs(PIN_B, 0);
	Pin dc(PIN_B, 1);
	Pin rst(PIN_B, 2);
	Pin mosi(PIN_B, 3);
	Pin sck(PIN_B, 4);
	OLED oled(mosi, sck, dc, rst, cs);
	oled.begin(false);
//	oled.drawBuffer(buffer, sizeof(buffer) / sizeof(uint8_t));
	while(1);
>>>>>>> 33c3aa8d7ff095119d9bff5165b288a4de0941c3
	return 0;
}
