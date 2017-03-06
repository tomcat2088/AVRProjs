/*
 * OLED.cpp
 *
 *  Created on: 2017年2月22日
 *      Author: ocean
 */

#include "OLED.h"
#include "SPI.h"

#define SSD1306_128_32
#define nBitsPerChannel 8

using namespace OCAPI;

OLED::OLED(Pin mosi, Pin sck, Pin dc, Pin rst, Pin cs) :
        spi(SPI(mosi, sck, dc, rst, cs)) {
    width = 128;
    height = 32;
}

OLED::OLED(Pin mosi, Pin sck, Pin dc, Pin rst, Pin cs, uint16_t width, uint16_t height) :
        spi(SPI(mosi, sck, dc, rst, cs)),
        width(width),
        height(height)
{

}

OLED::~OLED() {

}

void OLED::begin(bool useExternVcc) {
    spi.begin();

    // Init sequence
    spi.sendCommand(OLEDCommand_DisplayOff);                    // 0xAE
    spi.sendCommand(OLEDCommand_SetDisplayClockDiv);            // 0xD5
    spi.sendCommand(0x80);                           // the suggested ratio 0x80

    spi.sendCommand(OLEDCommand_SetMultiplex);                  // 0xA8
    spi.sendCommand(height - 1);

    spi.sendCommand(OLEDCommand_SetDisplayOffset);              // 0xD3
    spi.sendCommand(0x0);                                   // no offset
    spi.sendCommand(OLEDCommand_SetStartLine | 0x0);            // line #0
    spi.sendCommand(OLEDCommand_ChargePump);                    // 0x8D
    if (useExternVcc) {
        spi.sendCommand(0x10);
    } else {
        spi.sendCommand(0x14);
    }
    spi.sendCommand(OLEDCommand_MemoryMode);                    // 0x20
    spi.sendCommand(0x00);                                // 0x0 act like ks0108
    spi.sendCommand(OLEDCommand_SegRemap | 0x1);
    spi.sendCommand(OLEDCommand_ComScanDec);

#if defined SSD1306_128_32
    spi.sendCommand(OLEDCommand_SetComPins);                    // 0xDA
    spi.sendCommand(0x02);
    spi.sendCommand(OLEDCommand_SetContrast);                   // 0x81
    spi.sendCommand(0x8F);
#endif

    spi.sendCommand(OLEDCommand_SetPreCharge);                  // 0xd9
    if (useExternVcc) {
        spi.sendCommand(0x22);
    } else {
        spi.sendCommand(0xF1);
    }
    spi.sendCommand(OLEDCommand_SetVComDetect);                 // 0xDB
    spi.sendCommand(0x40);
    spi.sendCommand(OLEDCommand_DiaplayAllOn_Resume);           // 0xA4
    spi.sendCommand(OLEDCommand_NormalDisplay);                 // 0xA6

    spi.sendCommand(OLEDCommand_DeactivateScroll);

    spi.sendCommand(OLEDCommand_DisplayOn);
}

inline void beginDraw(OLED *oled) {
    oled->spi.sendCommand(OLEDCommand_ColumnAddr);
    oled->spi.sendCommand(0);   // Column start address (0 = reset)
    oled->spi.sendCommand(oled->width - 1); // Column end address (127 = reset)
    oled->spi.sendCommand(OLEDCommand_PageAddr);
    oled->spi.sendCommand(0); // Page start address (0 = reset)

    if (oled->height == 32)
    {
        oled->spi.sendCommand(3); // Page end address
    }

    oled->spi.cs.setHigh();
    oled->spi.dc.setHigh();
    oled->spi.cs.setLow();
}

inline void endDraw(OLED *oled) {
    oled->spi.cs.setHigh();
}

void OLED::drawBuffer(uint8_t *buffer, uint16_t bufferLen) {
    beginDraw(this);
    for (uint16_t i = 0; i < bufferLen; i++) {
            spi.sendData(buffer[i]);
    }
    endDraw(this);
}

void OLED::paint(Painter &painter) {
    uint16_t size;
    uint8_t *buffer = painter.getBuffer(&size);
    drawBuffer(buffer, size);
}
