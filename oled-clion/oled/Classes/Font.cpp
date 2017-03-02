//
// Created by wangyang on 17/3/2.
//

#include "Font.h"

void Font::loadCharBuffer(uint8_t ch, uint16_t **outBuffer, uint16_t *outBufferSize) {
    uint8_t chCount = FontLib[0];
    int chIndex = 0;
    for (int i = 1; i <= chCount; ++i) {
        if (FontLib[i] == ch) {
            chIndex = i - 1;
        }
    }
    int rangeIndex = 1 + chCount + chIndex;
    int len = FontLib[rangeIndex];
    int rangeStart = 1 + chCount * 2;
    for (int i = 0; i < chIndex; ++i) {
        rangeStart += FontLib[1 + chCount + i];
    }
    *outBuffer = FontLib + rangeStart;
    *outBufferSize = len;
}