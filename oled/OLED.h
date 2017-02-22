/*
 * OLED.h
 *
 *  Created on: 2017年2月22日
 *      Author: ocean
 */

#ifndef OLED_H_
#define OLED_H_

#include "Pin.h"

namespace OCAPI {
class SPI;

typedef enum {
	OLEDCommand_SetContrast = 0x81,
	OLEDCommand_DiaplayAllOn_Resume = 0xA4,
	OLEDCommand_DisplayAllOn = 0xA5,
	OLEDCommand_NormalDisplay = 0xA6,
	OLEDCommand_InvertDisplay = 0xA7,
	OLEDCommand_DisplayOff = 0xAE,
	OLEDCommand_DisplayOn = 0xAF,
} OLEDCommand;

class OLED {
public:
	OLED(Pin mosi, Pin sck, Pin dc, Pin rst, Pin cs);
	void begin();
	virtual ~OLED();

private:
	SPI *spi;
};

} /* namespace OCAPI */

#endif /* OLED_H_ */
