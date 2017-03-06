//
// Created by wang yang on 2017/3/1.
//

#ifndef OLED_CLION_TESTS_GRAPHICS_TESTS_H
#define OLED_CLION_TESTS_GRAPHICS_TESTS_H

#include "Graphics.h"
#define SSD1306_LCDHEIGHT 32
#define SSD1306_LCDWIDTH 128

class Graphics_tests {
public:
    void test_draw() {
        Painter painter;
        painter.clear();
        painter.beginPath();
        painter.moveTo(SSD1306_LCDWIDTH / 2, 0);
        painter.lineTo(SSD1306_LCDWIDTH, SSD1306_LCDHEIGHT / 2);
        painter.lineTo(0,0);
        painter.lineTo(0, SSD1306_LCDHEIGHT / 2);
        painter.closePath();
        painter.strokePath();
    }
};


#endif //OLED_CLION_TESTS_GRAPHICS_TESTS_H
