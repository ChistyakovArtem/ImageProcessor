//
// Created by artem on 26.03.2022.
//

#include "GrayScaleFilter.h"

GrayScaleFilter::GrayScaleFilter() = default;

std::vector<std::vector<Pixel> > GrayScaleFilter::ApplyTransformation(const std::vector<std::vector<Pixel>> &input) const {
    int height = static_cast<int> (input.size());
    int width = static_cast<int> (input[0].size());

    std::vector<std::vector<Pixel> > answer(height, std::vector<Pixel> (width, Pixel()));
    for (int height_i = 0; height_i < height; ++height_i) {
        for(int width_i = 0; width_i < width; ++width_i) {
            Pixel p = input[height_i][width_i];
            uint8_t gs = 0.299 * p.red_ + 0.587 * p.green_ + 0.114 * p.blue_;
            answer[height_i][width_i] = Pixel(gs, gs, gs);
        }
    }

    return answer;
}
