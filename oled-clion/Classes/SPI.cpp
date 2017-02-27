/*
 * SPI.cpp
 *
 *  Created on: 2017年2月22日
 *      Author: ocean
 */

#include "SPI.h"
#include <avr/delay.h>

using namespace OCAPI;

/**
 *  MOSI: 	Master Out Slaver In
 *  SCK:  	Clock
 *  DC:		Data 1 | Command 0
 *  RST:	Reset Communication
 *  CS: 	Chip Select
 * **/
SPI::SPI(Pin mosi, Pin sck, Pin dc, Pin rst, Pin cs) :
	mosi(mosi),
	sck(sck),
	dc(dc),
	rst(rst),
	cs(cs)
{

}

void SPI::begin() {
	// Set MOSI & SCK & DC & CS Output
	dc.setModeOut();
	cs.setModeOut();
	mosi.setModeOut();
	sck.setModeOut();

	// reset
	reset();
}

void SPI::reset() {
	rst.setModeOut();
	rst.setHigh();
	_delay_ms(1);
	rst.setLow();
	_delay_ms(10);
	rst.setHigh();
}

void SPI::sendCommand(unsigned char command) {
	// Enable chip & set DC to Command Mode
	cs.setHigh();
	dc.setLow();
	cs.setLow();

	// Send Data
	for(unsigned char bit = 0x80; bit; bit >>= 1) {
		// One bit will be transmitted when SCK change from low to high
		sck.setLow();
		if (command & bit) {
			mosi.setHigh();
		} else {
			mosi.setLow();
		}
		sck.setHigh();
	}

	// Disable Chip Select
	cs.setHigh();
}

SPI::~SPI() {

}

