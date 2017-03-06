/*
 * Pin.cpp
 *
 *  Created on: 2017年2月22日
 *      Author: ocean
 */

#include "Pin.h"
#include <avr/io.h>

using namespace OCAPI;

Pin::Pin(PINKind pinKind, unsigned char pinNo) :
		pinKind(pinKind), pinNo(pinNo) {

}

void Pin::setModeOut() {
	switch (pinKind) {
	case PIN_A:
		DDRA |= 1 << pinNo;
		break;
	case PIN_B:
		DDRB |= 1 << pinNo;
		break;
	case PIN_C:
		DDRC |= 1 << pinNo;
		break;
	case PIN_D:
		DDRD |= 1 << pinNo;
		break;
	}
}

void Pin::setModeIn() {
	switch (pinKind) {
	case PIN_A:
		DDRA &= ~(1 << pinNo);
		break;
	case PIN_B:
		DDRB &= ~(1 << pinNo);
		break;
	case PIN_C:
		DDRC &= ~(1 << pinNo);
		break;
	case PIN_D:
		DDRD &= ~(1 << pinNo);
		break;
	}
}

void Pin::setHigh() {
	switch (pinKind) {
	case PIN_A:
		PORTA |= 1 << pinNo;
		break;
	case PIN_B:
		PORTB |= 1 << pinNo;
		break;
	case PIN_C:
		PORTC |= 1 << pinNo;
		break;
	case PIN_D:
		PORTD |= 1 << pinNo;
		break;
	}
}

void Pin::setLow() {
	switch (pinKind) {
	case PIN_A:
		PORTA &= ~(1 << pinNo);
		break;
	case PIN_B:
		PORTB &= ~(1 << pinNo);
		break;
	case PIN_C:
		PORTC &= ~(1 << pinNo);
		break;
	case PIN_D:
		PORTD &= ~(1 << pinNo);
		break;
	}
}

unsigned char Pin::get() {
//	unsigned char val = PINXs[pinKind] & (1 << pinNo);
	return 0xaa;
}

