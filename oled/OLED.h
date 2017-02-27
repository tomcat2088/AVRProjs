/*
 * OLED.h
 *
 *  Created on: 2017年2月22日
 *      Author: ocean
 */

#ifndef OLED_H_
#define OLED_H_

#include "SPI.h"

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
	OLEDCommand_SetDisplayOffset = 0xD3,
	OLEDCommand_SetComPins = 0xDA,
	OLEDCommand_SetVComDetect = 0xDB,
	OLEDCommand_SetDisplayClockDiv = 0xD5,
	OLEDCommand_SetPreCharge = 0xD9,
	OLEDCommand_SetMultiplex = 0xA8,
	OLEDCommand_SetLowColumn = 0x00,
	OLEDCommand_SetHighColumn = 0x10,
	OLEDCommand_SetStartLine = 0x40,
	OLEDCommand_MemoryMode = 0x20,
	OLEDCommand_ColumnAddr = 0x21,
	OLEDCommand_PageAddr = 0x22,
	OLEDCommand_ComScanInc = 0xc0,
	OLEDCommand_ComScanDec = 0xc8,
	OLEDCommand_SegRemap = 0xa0,
	OLEDCommand_ChargePump = 0x8d,
	OLEDCommand_ExternalVCC = 0x1,
	OLEDCommand_SwitchCapVCC = 0x2,
	OLEDCommand_ActivateScroll = 0x2f,
	OLEDCommand_DeactivateScroll = 0x2e,
	OLEDCommand_SetVerticalScrollArea = 0xa3,
	OLEDCommand_RightHorizontalScroll = 0x26,
	OLEDCommand_LeftHorizontalScroll = 0x27,
	OLEDCommand_VerticalAndRightHorizontalScroll = 0x29,
	OLEDCommand_VerticalAndLeftHorizontalScroll = 0x2a
} OLEDCommand;

class OLED {
public:
	OLED(Pin mosi, Pin sck, Pin dc, Pin rst, Pin cs);
	void begin(bool useExternVcc);
// TODOs:
	void drawBuffer(uint8_t *buffer, uint16_t bufferLen);
	void drawLine(uint16_t x0,uint16_t y0, uint16_t x1,uint16_t y1);
	void drawText(const char *str);
	~OLED();

private:
	SPI spi;
	uint16_t width;
	uint16_t height;
};

} /* namespace OCAPI */

#endif /* OLED_H_ */
