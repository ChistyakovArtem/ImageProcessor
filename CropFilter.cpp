//
// Created by artem on 26.03.2022.
//

#include "CropFilter.h"

#include <algorithm>
#include <iostream>

CropFilter::CropFilter(int crop_height, int crop_width) {
    crop_height_ = crop_height;
    crop_width_ = crop_width;
}

std::vector<std::vector<Pixel> > CropFilter::ApplyTransformation(const std::vector<std::vector<Pixel>> &input) const {
    int height = static_cast<int> (input.size());
    int width = static_cast<int> (input[0].size());

    int delta_height = height - crop_height_;
    int delta_width = width - crop_width_;

    std::vector<std::vector<Pixel> > answer = input;

    std::reverse(answer.begin(), answer.end());
    for (int i = 0; i < delta_height; ++i) {
        answer.pop_back();
    }
    std::reverse(answer.begin(), answer.end());

    for (auto & i : answer) {
        for (int j = 0; j < delta_width; ++j) {
            i.pop_back();
        }
    }

    return answer;
}

CropFilter::CropFilter() {
    crop_width_ = crop_height_ = 0;
}
