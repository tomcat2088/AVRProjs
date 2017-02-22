/*
 * OLED.cpp
 *
 *  Created on: 2017年2月22日
 *      Author: ocean
 */

#include "OLED.h"
#include "SPI.h"

using namespace OCAPI;

OLED::OLED(Pin mosi, Pin sck, Pin dc, Pin rst, Pin cs) : spi(SPI(mosi, sck, dc, rst, cs)) {
}

OLED::~OLED() {

}

void OLED::begin() {
#define SSD1306_128_32
#define SSD1306_LCDHEIGHT 32
	spi.begin();

	// Init sequence
	  spi.sendCommand(SSD1306_DISPLAYOFF);                    // 0xAE
	  spi.sendCommand(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
	  spi.sendCommand(0x80);                                  // the suggested ratio 0x80

	  spi.sendCommand(SSD1306_SETMULTIPLEX);                  // 0xA8
	  spi.sendCommand(32 - 1);

	  spi.sendCommand(SSD1306_SETDISPLAYOFFSET);              // 0xD3
	  spi.sendCommand(0x0);                                   // no offset
	  spi.sendCommand(SSD1306_SETSTARTLINE | 0x0);            // line #0
	  spi.sendCommand(SSD1306_CHARGEPUMP);                    // 0x8D
	  if (SSD1306_SWITCHCAPVCC == SSD1306_EXTERNALVCC)
	    { spi.sendCommand(0x10); }
	  else
	    { spi.sendCommand(0x14); }
	  spi.sendCommand(SSD1306_MEMORYMODE);                    // 0x20
	  spi.sendCommand(0x00);                                  // 0x0 act like ks0108
	  spi.sendCommand(SSD1306_SEGREMAP | 0x1);
	  spi.sendCommand(SSD1306_COMSCANDEC);

	 #if defined SSD1306_128_32
	  spi.sendCommand(SSD1306_SETCOMPINS);                    // 0xDA
	  spi.sendCommand(0x02);
	  spi.sendCommand(SSD1306_SETCONTRAST);                   // 0x81
	  spi.sendCommand(0x8F);

	#elif defined SSD1306_128_64
	  spi.sendCommand(SSD1306_SETCOMPINS);                    // 0xDA
	  spi.sendCommand(0x12);
	  spi.sendCommand(SSD1306_SETCONTRAST);                   // 0x81
	  if (vccstate == SSD1306_EXTERNALVCC)
	    { spi.sendCommand(0x9F); }
	  else
	    { spi.sendCommand(0xCF); }

	#elif defined SSD1306_96_16
	  spi.sendCommand(SSD1306_SETCOMPINS);                    // 0xDA
	  spi.sendCommand(0x2);   //ada x12
	  spi.sendCommand(SSD1306_SETCONTRAST);                   // 0x81
	  if (vccstate == SSD1306_EXTERNALVCC)
	    { spi.sendCommand(0x10); }
	  else
	    { spi.sendCommand(0xAF); }

	#endif

	  spi.sendCommand(SSD1306_SETPRECHARGE);                  // 0xd9
	  if (SSD1306_SWITCHCAPVCC == SSD1306_EXTERNALVCC)
	    { spi.sendCommand(0x22); }
	  else
	    { spi.sendCommand(0xF1); }
	  spi.sendCommand(SSD1306_SETVCOMDETECT);                 // 0xDB
	  spi.sendCommand(0x40);
	  spi.sendCommand(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
	  spi.sendCommand(SSD1306_NORMALDISPLAY);                 // 0xA6

	  spi.sendCommand(SSD1306_DEACTIVATE_SCROLL);

	  spi.sendCommand(SSD1306_DISPLAYON);


	  spi.sendCommand(SSD1306_COLUMNADDR);
	    spi.sendCommand(0);   // Column start address (0 = reset)
	    spi.sendCommand(128-1); // Column end address (127 = reset)

	    spi.sendCommand(SSD1306_PAGEADDR);
	    spi.sendCommand(0); // Page start address (0 = reset)
	    #if SSD1306_LCDHEIGHT == 64
	      spi.sendCommand(7); // Page end address
	    #endif
	    #if SSD1306_LCDHEIGHT == 32
	      spi.sendCommand(3); // Page end address
	    #endif
	    #if SSD1306_LCDHEIGHT == 16
	      spi.sendCommand(1); // Page end address
	    #endif

	      spi.cs.setHigh();
	      spi.dc.setHigh();
	      spi.cs.setLow();

	      unsigned char buffer = 0x80;
	      for (uint16_t i=0; i<(128*32/8); i++) {
	    	// Send Data
	    	for(unsigned char bit = 0x80; bit; bit >>= 1) {
	    		// One bit will be transmitted when SCK change from low to high
	    		spi.sck.setLow();
	    		if (buffer & bit) {
	    			spi.mosi.setHigh();
	    		} else {
	    			spi.mosi.setLow();
	    		}
	    		spi.sck.setHigh();
	    	}
	      }
	  spi.cs.setHigh();
}

