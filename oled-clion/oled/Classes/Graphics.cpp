//
// Created by wangyang on 17/2/27.
//

#include <stdlib.h>
#include <string.h>
#include "Graphics.h"

#define _swap_int16_t(a, b) { int16_t t = a; a = b; b = t; }


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
        uint8_t triggerMask = 0xff;
        for (int col = 0; col < width; ++col) {
            uint8_t lastFillTrigger = fillTrigger;
            fillTrigger ^= _buffer[row * width + col];
            if (col < width - 1) {
                uint8_t controlByte = _buffer[row * width + col] & _buffer[row * width + col + 1];
                fillTrigger &= ~controlByte;
                fillTrigger |= lastFillTrigger & controlByte;
            }
        }
        triggerMask = ~fillTrigger;
        fillTrigger = 0x00;
        for (int col = 0; col < width; ++col) {
            uint8_t lastFillTrigger = fillTrigger;
            fillTrigger ^= _buffer[row * width + col];
            if (col < width - 1) {
                uint8_t controlByte = _buffer[row * width + col] & _buffer[row * width + col + 1];
                fillTrigger &= ~controlByte;
                fillTrigger |= lastFillTrigger & controlByte;
            }
            _buffer[row * width + col] |= fillTrigger & triggerMask;
        }
    }
}

void Painter::drawLines(Line *lines, uint16_t lineCount) {
    for (int i = 0; i < lineCount; ++i) {
        drawLine(lines[i]);
    }
}

void Painter::drawText(const char *str) {
    const char *pChar = str;
    while (pChar != )
}

void Painter::beginPath() {
    _linesSize = 0;
}

void Painter::moveTo(int16_t x, int16_t y) {
    pathStartLocation = MakePoint(x, y);
}

void Painter::lineTo(int16_t x, int16_t y) {
//    if (_lines.size() > 0) {
////        Line *line = (Line *)_lines.at(_lines.size() - 1);
//        _lines.add(heap_MakeLine(pathStartLocation.x, pathStartLocation.y, x, y));
//    } else {
//        _lines.add(heap_MakeLine(pathStartLocation.x, pathStartLocation.y, x, y));
//    }
    if (_linesSize > 0) {
        Line line = _lines[_linesSize - 1];
        _lines[_linesSize] = MakeLine(line.end.x, line.end.y, x, y);
    } else {
        _lines[_linesSize] = MakeLine(pathStartLocation.x, pathStartLocation.y, x, y);
    }
    _linesSize++;
}

void Painter::closePath() {
//    Line *line = (Line *)_lines.at(_lines.size() - 1);
//    _lines.add(heap_MakeLine(line->end.x, line->end.y, pathStartLocation.x, pathStartLocation.y));

    Line line = _lines[_linesSize - 1];
    _lines[_linesSize] = MakeLine(line.end.x, line.end.y, pathStartLocation.x, pathStartLocation.y);
    _linesSize++;
}

void Painter::strokePath() {
    drawLines(_lines, _linesSize);
}

void Painter::fillPath() {
    drawLines(_lines, _linesSize);
    fillBufferShape();
}