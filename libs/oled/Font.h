//
// Created by wangyang on 17/3/2.
//

#ifndef OLED_CLION_FONT_H
#define OLED_CLION_FONT_H

#define Use_Font_Arial

#include <avr/io.h>
#include "FontArial.h"

class Font {
public:
    void loadCharBuffer(uint8_t ch, uint8_t **outBuffer, uint16_t *outBufferSize);
};


#endif //OLED_CLION_FONT_H
