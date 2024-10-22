////////////////////////////////////////////////////////////////////////////                
//                
//
//                          oled.hpp
//
//
////////////////////////////////////////////////////////////////////////////

#pragma once

#include <bcm2835.h>
#include <cstdio>
#include <SSD1306_OLED.hpp>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>

namespace OLED{
    class Oled_t {
    public:
        Oled_t(uint16_t width, uint16_t height, uint16_t i2c_speed, uint8_t i2c_address);
        ~Oled_t();

        bool begin(bool i2c_debug = false);
        void clearScreen();
        void displayText(const char* text, int x, int y);
        void displayTextScroll(const char* text, int x, int y) ;
        void powerDown();
        void demo();
        const std::vector <std::string>& convertToMayuscule(std::vector <std::string>& display_text);
    
    protected:
        bool initI2C();
        void closeI2C();

    private:
        uint16_t myOLEDwidth;
        uint16_t myOLEDheight;                           
        uint16_t i2c_speed_;
        uint8_t i2c_address_;
        bool i2c_debug_;
        uint8_t* screenBuffer_;
        SSD1306 myOLED;
    };
}
