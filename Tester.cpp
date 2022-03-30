//
// Created by artem on 29.03.2022.
//

#include "Tester.h"

#include <iostream>

Tester::Tester() = default;

bool operator !=(Pixel a, Pixel b) {
    return ! ((a.red_ == b.red_) && (a.green_ == b.green_) && (a.blue_ == b.blue_));
}

bool operator ==(const std::vector<std::vector<Pixel>>& a, const std::vector<std::vector<Pixel>>& b) {
    if (a.size() != b.size()) {
        return false;
    }
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i].size() != b[i].size()) {
            return false;
        }
        for (size_t j = 0; j < a[i].size(); ++j) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Tester::test_convolution(int test_case) {
    if (test_case == 0) {
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

        std::vector<std::vector<Pixel> > input = {{Pixel(100, 100, 100), Pixel(0, 0, 0), Pixel(0, 0, 0)},
                                                  {Pixel(100, 100, 100), Pixel(100, 100, 100), Pixel(0, 0, 0)},
                                                  {Pixel(100, 100, 100), Pixel(100, 100, 100), Pixel(100, 100, 100)},
        };
        std::vector<std::vector<Pixel> > predicted = {{Pixel(200, 200, 200), Pixel(0, 0, 0), Pixel(0, 0, 0)},
                                                      {Pixel(100, 100, 100), Pixel(255, 255, 255), Pixel(0, 0, 0)},
                                                      {Pixel(100, 100, 100), Pixel(100, 100, 100), Pixel(200, 200, 200)}
        };
        auto conv_test = ApplyConvolution(input);
        std::cout << (conv_test == predicted) << std::endl;
    }

}