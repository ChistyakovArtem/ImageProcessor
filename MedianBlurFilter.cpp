//
// Created by artem on 27.03.2022.
//

#include "MedianBlurFilter.h"

#include <iostream>
#include <algorithm>

MedianBlurFilter::MedianBlurFilter(int receptor_field_size) {
    if (receptor_field_size % 2 == 0) {
        std::cout << "Receptor field size must be odd" << std::endl;
    }
    receptor_field_size_ = receptor_field_size;
}

MedianBlurFilter::MedianBlurFilter() = default;

std::vector<std::vector<Pixel> >
MedianBlurFilter::ApplyTransformation(const std::vector<std::vector<Pixel>> &input) const {
    int image_height = static_cast<int> (input.size());
    int image_width = static_cast<int> (input[0].size());

    std::vector<std::vector<Pixel> > answer(image_height, std::vector<Pixel> (image_width, Pixel()));
    for (int height_i = 0; height_i < image_height; ++height_i) {
        for (int width_i = 0; width_i < image_width; ++width_i) {

            std::vector<int> red_values_in_field;
            std::vector<int> green_values_in_field;
            std::vector<int> blue_values_in_field;

            int start_height = std::max(0, height_i - receptor_field_size_ / 2);
            int finish_height = std::min(image_height - 1, height_i + receptor_field_size_ / 2);

            int start_width = std::max(0, width_i - receptor_field_size_ / 2);
            int finish_width = std::min(image_width - 1, width_i + receptor_field_size_ / 2);

            for (int kernel_height = start_height; kernel_height <= finish_height; ++kernel_height) {
                for (int kernel_width = start_width; kernel_width <= finish_width; ++kernel_width) {
                    red_values_in_field.push_back(input[kernel_height][kernel_width].red_);
                    green_values_in_field.push_back(input[kernel_height][kernel_width].green_);
                    blue_values_in_field.push_back(input[kernel_height][kernel_width].blue_);
                }
            }

            std::sort(red_values_in_field.begin(), red_values_in_field.end());
            std::sort(green_values_in_field.begin(), green_values_in_field.end());
            std::sort(blue_values_in_field.begin(), blue_values_in_field.end());

            int red_median = red_values_in_field[red_values_in_field.size() / 2];
            int green_median = green_values_in_field[green_values_in_field.size() / 2];
            int blue_median = blue_values_in_field[blue_values_in_field.size() / 2];

            answer[height_i][width_i] = Pixel(red_median, green_median, blue_median);
        }
    }
    return answer;
}