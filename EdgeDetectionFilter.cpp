//
// Created by artem on 26.03.2022.
//

#include "EdgeDetectionFilter.h"

EdgeDetectionFilter::EdgeDetectionFilter(uint8_t threshold) {
    threshold_ = threshold;

    int16_t tmp[3][3] = {{0, -1, 0},
                         {-1, 4, -1},
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
};

std::vector<std::vector<Pixel> >
EdgeDetectionFilter::ApplyTransformation(const std::vector<std::vector<Pixel>> &input) const {
    // to gray-scale
    std::vector<std::vector<Pixel> > answer = GrayScaleFilter::ApplyTransformation(input);

    // edge detection
    answer = ApplyConvolution(answer);

    //
    int height = static_cast<int> (input.size());
    int width = static_cast<int> (input[0].size());
    for (int height_i = 0; height_i < height; ++height_i) {
        for(int width_i = 0; width_i < width; ++width_i) {
            bool is_white = (answer[height_i][width_i].red_ > threshold_); // all colors values the same
            uint8_t color = (is_white) ? 255 : 0;
            answer[height_i][width_i] = Pixel(color, color, color);
        }
    }

    return answer;
}

EdgeDetectionFilter::EdgeDetectionFilter() {
    threshold_ = 0;
}

