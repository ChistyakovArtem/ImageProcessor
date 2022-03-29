//
// Created by artem on 26.03.2022.
//

#include "ConvolutionOperation.h"

#include <iostream>

ConvolutionOperation::ConvolutionOperation() = default;

std::vector<std::vector<Pixel> > ConvolutionOperation::ApplyConvolution(const std::vector<std::vector<Pixel>> &input) const {
    int image_height = static_cast<int> (input.size());
    int image_width = static_cast<int> (input[0].size());

    std::vector<std::vector<Pixel> > answer(image_height, std::vector<Pixel> (image_width, Pixel()));
    for (int height_i = 0; height_i < image_height; ++height_i) {
        for (int width_i = 0; width_i < image_width; ++width_i) {
            int scalar_product_red = 0;
            int scalar_product_green = 0;
            int scalar_product_blue = 0;
            for (int kernel_height_i = 0; kernel_height_i < kernel_height; ++kernel_height_i) {
                for (int kernel_width_i = 0; kernel_width_i < kernel_width; ++kernel_width_i) {
                    int pixel_height = std::min(image_height - 1, std::max(0, height_i - kernel_height / 2 + kernel_height_i));
                    int pixel_width = std::min(image_width - 1, std::max(0, width_i - kernel_width / 2 + kernel_width_i));

                    int kernel_pixel = kernel_[kernel_height_i][kernel_width_i];
                    Pixel input_pixel = input[pixel_height][pixel_width];

                    scalar_product_red += kernel_pixel * input_pixel.red_;
                    scalar_product_green += kernel_pixel * input_pixel.green_;
                    scalar_product_blue += kernel_pixel * input_pixel.blue_;
                }
            }
            scalar_product_red = std::min(255, std::max(scalar_product_red, 0)); // clip
            scalar_product_red = static_cast<uint8_t>(scalar_product_red);

            scalar_product_green = std::min(255, std::max(scalar_product_green, 0)); // clip
            scalar_product_green = static_cast<uint8_t>(scalar_product_green);

            scalar_product_blue = std::min(255, std::max(scalar_product_blue, 0)); // clip
            scalar_product_blue = static_cast<uint8_t>(scalar_product_blue);

            answer[height_i][width_i] = Pixel(scalar_product_red, scalar_product_green, scalar_product_blue);
        }
    }

    return answer;
}
