/*
 * Pin.cpp
 *
 *  Created on: 2017年2月22日
 *      Author: ocean
 */

#include "Pin.h"

using namespace OCAPI;

Pin::Pin(PINKind pinKind, unsigned char pinNo) :
		pinKind(pinKind),
		pinNo(pinNo)
{

}

void Pin::setModeOut() {
	DDRXs[pinKind] |= 1 << pinNo;
}

void Pin::setModeIn() {
	DDRXs[pinKind] &= ~(1 << pinNo);
}

void Pin::setHigh() {
	PORTXs[pinKind] |= 1 << pinNo;
}

void Pin::setLow() {
	PORTXs[pinKind] &= ~(1 << pinNo);
}

unsigned char Pin::get() {
	unsigned char val = PINXs[pinKind] & (1 << pinNo);
	return val;
}


