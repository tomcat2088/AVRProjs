/*
 * Pin.h
 *
 *  Created on: 2017年2月22日
 *      Author: ocean
 */

#ifndef PIN_H_
#define PIN_H_

#include <avr/io.h>

namespace OCAPI {

static unsigned char DDRXs[] = {
		DDRA,
		DDRB,
		DDRC,
		DDRD
};

static unsigned char PORTXs[] = {
		PORTA,
		PORTB,
		PORTC,
		PORTD
};

static unsigned char PINXs[] = {
		PINA,
		PINB,
		PINC,
		PIND
};

typedef enum {
	PIN_A,
	PIN_B,
	PIN_C,
	PIN_D
}PINKind;

typedef enum {
	PINMode_Out,
	PINMode_In
}PINMode;

class Pin {
public:
	Pin(PINKind pinKind, unsigned char pinNo);
	void setModeOut();
	void setModeIn();
	void setHigh();
	void setLow();
	unsigned char get();

public:
	PINKind pinKind;
	unsigned char pinNo;

};

} /* namespace OCAPI */

#endif /* PIN_H_ */
