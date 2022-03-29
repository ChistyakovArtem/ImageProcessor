//
// Created by artem on 27.03.2022.
//

#include "GaussianBlurFilter.h"

#include <cmath>
#include <iostream>

GaussianBlurFilter::GaussianBlurFilter(double sigma) {
    int kernel_dim = (static_cast<int>(6 * sigma) / 2 * 2) + 3;
    int hd = kernel_dim / 2;
    kernel_height = kernel_width = kernel_dim;
    double_kernel_ = std::vector<std::vector<double> > (kernel_height, std::vector<double>(kernel_width, 0));
    double r = 0;
    double s = 2.0 * sigma * sigma;

    // sum is for normalization
    double sum = 0.0;
    // generating 5x5 kernel
    for (int x = -hd; x <= hd; x++) {
        for (int y = -hd; y <= hd; y++) {
            r = sqrt(x * x + y * y);
            double_kernel_[x + hd][y + hd] = (exp(-(r * r) / s)) / (M_PI * s);
            sum += double_kernel_[x + hd][y + hd];
        }
    }

    // normalising the Kernel
    for (int i = 0; i < kernel_height; ++i) {
        for (int j = 0; j < kernel_width; ++j) {
            double_kernel_[i][j] /= sum;
        }
    }
}

GaussianBlurFilter::GaussianBlurFilter() = default;

std::vector<std::vector<Pixel> >
GaussianBlurFilter::ApplyTransformation(const std::vector<std::vector<Pixel>> &input) const {
    int image_height = static_cast<int> (input.size());
    int image_width = static_cast<int> (input[0].size());

    std::vector<std::vector<Pixel> > answer(image_height, std::vector<Pixel> (image_width, Pixel()));
    for (int height_i = 0; height_i < image_height; ++height_i) {
        for (int width_i = 0; width_i < image_width; ++width_i) {
            double scalar_product_red = 0;
            double scalar_product_green = 0;
            double scalar_product_blue = 0;
            for (int kernel_height_i = 0; kernel_height_i < kernel_height; ++kernel_height_i) {
                for (int kernel_width_i = 0; kernel_width_i < kernel_width; ++kernel_width_i) {
                    int pixel_height = std::min(image_height - 1, std::max(0, height_i - kernel_height / 2 + kernel_height_i));
                    int pixel_width = std::min(image_width - 1, std::max(0, width_i - kernel_width / 2 + kernel_width_i));

                    double kernel_pixel = double_kernel_[kernel_height_i][kernel_width_i];
                    Pixel input_pixel = input[pixel_height][pixel_width];

                    scalar_product_red += kernel_pixel * input_pixel.red_;
                    scalar_product_green += kernel_pixel * input_pixel.green_;
                    scalar_product_blue += kernel_pixel * input_pixel.blue_;
                }
            }

            scalar_product_red = std::min(255.0, std::max(scalar_product_red, 0.0)); // clip
            scalar_product_green = std::min(255.0, std::max(scalar_product_green, 0.0)); // clip
            scalar_product_blue = std::min(255.0, std::max(scalar_product_blue, 0.0)); // clip

            answer[height_i][width_i] = Pixel(static_cast<uint8_t>(scalar_product_red),
                                              static_cast<uint8_t>(scalar_product_green),
                                              static_cast<uint8_t>(scalar_product_blue));
        }
    }

    return answer;
}

