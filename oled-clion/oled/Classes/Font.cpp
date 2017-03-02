//
// Created by wangyang on 17/3/2.
//

#include "Font.h"

void Font::loadCharBuffer(uint8_t ch, uint8_t **outBuffer, uint16_t *outBufferSize) {
    uint8_t chCount = FontLib[0];
    uint16_t chIndex = 0;
    for (uint16_t i = 1; i <= chCount; ++i) {
        if (FontLib[i] == ch) {
            chIndex = i - 1;
        }
    }
    uint16_t rangeIndex = 1 + chCount + chIndex;
    uint8_t len = FontLib[rangeIndex];
    uint16_t rangeStart = 1 + chCount * 2;
    for (uint16_t i = 0; i < chIndex; ++i) {
        rangeStart += FontLib[1 + chCount + i];
    }
    *outBuffer = FontLib + rangeStart;
    *outBufferSize = len;
}