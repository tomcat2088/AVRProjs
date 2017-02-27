#include <avr/io.h>

#include "Pin.h"

using namespace OCAPI;

int main() {
	Pin pb4(PIN_A, 4);
	pb4.setModeOut();
	pb4.setHigh();
	return 0;
}
