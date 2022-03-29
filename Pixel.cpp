//
// Created by artem on 26.03.2022.
//

#include <tuple>
#include "Pixel.h"

Pixel::Pixel(uint8_t red, uint8_t green, uint8_t blue) {
    red_ = red;
    green_ = green;
    blue_ = blue;
}

Pixel::Pixel() {
    red_ = green_ = blue_ = 0;
}
