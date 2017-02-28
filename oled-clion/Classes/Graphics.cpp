//
// Created by wangyang on 17/2/27.
//

#include <stdlib.h>
#include <string.h>
#include "Graphics.h"

#define Small_Float 0.000001
#define _swap_int16_t(a, b) { int16_t t = a; a = b; b = t; }

bool Graphics::pointOnLine(Point point, Line line) {
    float xScale = (line.end.x - point.x) / (float)(point.x - line.start.x);
    float yScale = (line.end.y - point.y) / (float)(point.y - line.start.y);
    float delta = yScale - xScale;

    if (xScale >= 0 && yScale >= 0 && delta < Small_Float && delta > -Small_Float) {
        return true;
    }
    return false;
}

Painter::Painter(uint16_t width, uint16_t height) :
    width(width),
    height(height)
{
    _buffer = (uint8_t *)malloc(width * height / 8);
    clear();
}

uint8_t * Painter::getBuffer(uint16_t *bufferSize) {
    *bufferSize = width * height / 8;
    return _buffer;
}

void Painter::clear() {
    memset(_buffer, 0x00, width * height / 8);
}

void Painter::drawPixel(Point point) {
    int16_t loc = point.y / 8 * width + point.x;
    _buffer[loc] |= 0x01 << (point.y % 8);
}

void Painter::drawLine(Line line) {
    uint16_t x0 = line.start.x;
    uint16_t y0 = line.start.y;
    uint16_t x1 = line.end.x;
    uint16_t y1 = line.end.y;
    int16_t steep = abs(y1 - y0) > abs(x1 - x0);
    if (steep) {
        _swap_int16_t(x0, y0);
        _swap_int16_t(x1, y1);
    }

    if (x0 > x1) {
        _swap_int16_t(x0, x1);
        _swap_int16_t(y0, y1);
    }

    int16_t dx, dy;
    dx = x1 - x0;
    dy = abs(y1 - y0);

    int16_t err = dx / 2;
    int16_t ystep;

    if (y0 < y1) {
        ystep = 1;
    } else {
        ystep = -1;
    }

    for (; x0<=x1; x0++) {
        if (steep) {
            Point point = {y0, x0};
            drawPixel(point);
        } else {
            Point point = {x0, y0};
            drawPixel(point);
        }
        err -= dy;
        if (err < 0) {
            y0 += ystep;
            err += dx;
        }
    }
}

void Painter::drawRect(Rect rect) {
   drawLine(MakeLine(rect.origin.x,rect.origin.y,rect.origin.x + rect.width,rect.origin.y));
   drawLine(MakeLine(rect.origin.x + rect.width,rect.origin.y,rect.origin.x + rect.width,rect.origin.y + rect.height));
   drawLine(MakeLine(rect.origin.x + rect.width,rect.origin.y + rect.height,rect.origin.x,rect.origin.y + rect.height));
   drawLine(MakeLine(rect.origin.x,rect.origin.y + rect.height,rect.origin.x,rect.origin.y));
}

void Painter::fillBufferShape() {
    uint8_t lastVal = 0x00;
    uint8_t fillTrigger = 0x00;
    for (int row = 0; row < height / 8; ++row) {
        uint8_t fillTrigger = 0x00;
        for (int col = 0; col < width; ++col) {
            uint8_t lastFillTrigger = fillTrigger;
            fillTrigger ^= _buffer[row * width + col];
            if (col < width - 1) {
                uint8_t controlByte = _buffer[row * width + col] & _buffer[row * width + col + 1];
                fillTrigger &= ~controlByte;
                fillTrigger |= lastFillTrigger & controlByte;
            }
            _buffer[row * width + col] |= fillTrigger;
        }
    }
}

void Painter::drawLines(Line *line, uint16_t lineCount) {

}

void Painter::drawText(const char *str) {

}
