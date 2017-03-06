#include <avr/io.h>
#include <Graphics.h>

#include "OLED.h"
#include "LinkedArray.h"
#include "math.h"

using namespace OCAPI;

#define SSD1306_LCDHEIGHT 32
#define SSD1306_LCDWIDTH 128

int main() {
    // setup OLED Pins
    Pin cs(PIN_B, 0);
    Pin dc(PIN_B, 1);
    Pin rst(PIN_B, 2);
    Pin mosi(PIN_B, 3);
    Pin sck(PIN_B, 4);
    OLED oled(mosi, sck, dc, rst, cs, SSD1306_LCDWIDTH, SSD1306_LCDHEIGHT);

    // setup oled registers
    oled.begin(false);
    Painter painter(SSD1306_LCDWIDTH, SSD1306_LCDHEIGHT);

    painter.drawText("NRF");
    oled.paint(painter);


    return 0;
}
