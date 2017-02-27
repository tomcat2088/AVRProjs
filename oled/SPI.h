/*
 * SPI.h
 *
 *  Created on: 2017年2月22日
 *      Author: ocean
 */

#ifndef SPI_H_
#define SPI_H_

#include "Pin.h"

namespace OCAPI {

class SPI {
public:
	SPI();
	SPI(Pin mosi, Pin sck, Pin dc, Pin rst, Pin cs);
	void begin();
	void reset();
	void sendCommand(unsigned char command);

	~SPI();

public :
	Pin mosi;
	Pin sck;
	Pin dc;
	Pin rst;
	Pin cs;

};

} /* namespace OCAPI */

#endif /* SPI_H_ */
