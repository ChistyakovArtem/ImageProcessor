//
// Created by artem on 26.03.2022.
//

#include "NegativeFilter.h"

NegativeFilter::NegativeFilter() = default;

std::vector<std::vector<Pixel> > NegativeFilter::ApplyTransformation(const std::vector<std::vector<Pixel>> &input) const {
    int height = static_cast<int> (input.size());
    int width = static_cast<int> (input[0].size());

    std::vector<std::vector<Pixel> > answer(height, std::vector<Pixel> (width, Pixel()));
    for (int height_i = 0; height_i < height; ++height_i) {
        for(int width_i = 0; width_i < width; ++width_i) {
            Pixel p = input[height_i][width_i];
            answer[height_i][width_i] = Pixel(1 - p.red_, 1 - p.green_, 1 - p.blue_);
        }
    }
    return answer;
}

