//
// Created by wangyang on 17/2/27.
//

#ifndef OLED_CLION_GRAPHICS_H
#define OLED_CLION_GRAPHICS_H

#include <stdint.h>

typedef struct {
    uint16_t x;
    uint16_t y;
} Point;

typedef struct {
    Point start;
    Point end;
} Line;

class Graphics {
public:
    static bool pointOnLine(Point point, Line line);
};


#endif //OLED_CLION_GRAPHICS_H
