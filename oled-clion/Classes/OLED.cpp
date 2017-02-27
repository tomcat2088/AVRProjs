/*
 * OLED.cpp
 *
 *  Created on: 2017年2月22日
 *      Author: ocean
 */

#include "OLED.h"
#include "SPI.h"

using namespace OCAPI;

OLED::OLED(Pin mosi, Pin sck, Pin dc, Pin rst, Pin cs) {
	spi = new SPI(mosi, sck, dc, rst, cs);
}

OLED::~OLED() {
	delete spi;
}

void OLED::begin() {
	spi->begin();
	spi->sendCommand(OLEDCommand_DisplayOff);
	spi->sendCommand(OLEDCommand_DisplayOff);
}

