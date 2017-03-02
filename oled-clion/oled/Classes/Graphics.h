//
// Created by wangyang on 17/2/27.
//

#ifndef OLED_CLION_GRAPHICS_H
#define OLED_CLION_GRAPHICS_H

#include <stdint.h>
#include "LinkedArray.h"

typedef struct {
    uint16_t x;
    uint16_t y;
} Point;

typedef struct {
    Point start;
    Point end;
} Line;

typedef struct {
    Point origin;
    uint16_t width;
    uint16_t height;
} Rect;

static inline Line MakeLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
    Line line;
    Point start = {x0, y0};
    Point end = {x1, y1};
    line.start = start;
    line.end = end;
    return line;
}

static inline Point MakePoint(uint16_t x, uint16_t y) {
    Point pt = {x, y};
    return pt;
}

static inline Rect MakeRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h) {
    Rect rect;
    Point origin = {x, y};
    rect.origin = origin;
    rect.width = w;
    rect.height = h;
    return rect;
}

// use malloc to Make line / point / rect
static inline Line * heap_MakeLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
    Line *line = (Line *)malloc(sizeof(Line));
    Point start = {x0, y0};
    Point end = {x1, y1};
    line->start = start;
    line->end = end;
    return line;
}

static inline Point * heap_MakePoint(uint16_t x, uint16_t y) {
    Point *pt = (Point *)malloc(sizeof(Point));
    return pt;
}

static inline Rect * heap_MakeRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h) {
    Rect * rect = (Rect *)malloc(sizeof(Rect));
    Point origin = {x, y};
    rect->origin = origin;
    rect->width = w;
    rect->height = h;
    return rect;
}


class Painter {
public:
    Painter(uint16_t width, uint16_t height);
    uint8_t * getBuffer(uint16_t *bufferSize);

    void clear();
    void drawPixel(Point point);
    void drawLine(Line line);
    void drawRect(Rect rect);
    void fillBufferShape();
    void drawLines(Line *lines, uint16_t lineCount);
    void drawText(const char *str);

    void beginPath();
    void moveTo(int16_t x, int16_t y);
    void lineTo(int16_t x, int16_t y);
    void closePath();
    void strokePath();
    void fillPath();
private:
    uint8_t *_buffer;
    uint16_t width;
    uint16_t height;

    Line _lines[3];
    uint8_t _linesSize;
    Point pathStartLocation;
};


#endif //OLED_CLION_GRAPHICS_H
