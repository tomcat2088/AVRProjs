#include <avr/io.h>

#include "Pin.h"
#include "OLED.h"

using namespace OCAPI;

int main() {
	Pin cs(PIN_B, 0);
	Pin dc(PIN_B, 1);
	Pin rst(PIN_B, 2);
	Pin mosi(PIN_B, 3);
	Pin sck(PIN_B, 4);
	//OLED oled(mosi, sck, dc, rst, cs);
	//oled.begin();
	DDRB = 0xff;
sck.setHigh();
	while(1);
	return 0;
}
