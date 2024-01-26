#ifndef __oled_h
#define __oled_h
#include <Adafruit_SSD1306.h>
#include "../reflow.h"
class OledDisplay {
    public:
        OledDisplay();
        void setup();
        void loop();
        void teardown();

    private:
        Adafruit_SSD1306 display;
};



#endif