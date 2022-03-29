//
// Created by artem on 26.03.2022.
//

#ifndef IMAGE_PROCESSOR_PIXEL_H
#define IMAGE_PROCESSOR_PIXEL_H


#include <cstdint>

class Pixel {
public:
    uint8_t red_;
    uint8_t green_;
    uint8_t blue_;

    Pixel(uint8_t red, uint8_t green, uint8_t blue);
    Pixel();
};

#endif //IMAGE_PROCESSOR_PIXEL_H
