//
// Created by artem on 26.03.2022.
//

#include "SharpFilter.h"

SharpFilter::SharpFilter() {
     int16_t tmp[3][3] = {{0, -1, 0},
                       {-1, 5, -1},
                       {0, -1, 0}};

    kernel_height = 3;
    kernel_width = 3;
    kernel_ = std::vector<std::vector<int16_t> > (kernel_height, std::vector<int16_t>(kernel_width, 0));

    // how to do it normally
     for (int i = 0; i < kernel_height; ++i) {
         for(int j = 0; j < kernel_width; ++j) {
             kernel_[i][j] = tmp[i][j];
         }
     }
}

std::vector<std::vector<Pixel> > SharpFilter::ApplyTransformation(const std::vector<std::vector<Pixel>> &input) const {
    return ApplyConvolution(input);
}
