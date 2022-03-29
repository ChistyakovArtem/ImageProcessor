//
// Created by artem on 27.03.2022.
//

#include "SaltAndPepperFilter.h"
#include <ctime>
#include <cstdlib>

SaltAndPepperFilter::SaltAndPepperFilter(double salt_probability, double pepper_probability) {
    salt_probability_ = salt_probability;
    pepper_probability_ = pepper_probability;
}

SaltAndPepperFilter::SaltAndPepperFilter() = default;

std::vector<std::vector<Pixel> >
SaltAndPepperFilter::ApplyTransformation(const std::vector<std::vector<Pixel>> &input) const {
    int height = static_cast<int> (input.size());
    int width = static_cast<int> (input[0].size());

    std::srand(std::time(nullptr));
    std::vector<std::vector<Pixel> > answer(height, std::vector<Pixel> (width, Pixel()));
    for (int height_i = 0; height_i < height; ++height_i) {
        for(int width_i = 0; width_i < width; ++width_i) {
            answer[height_i][width_i] = input[height_i][width_i];
            double salt_random = 1.0 * std::rand() / RAND_MAX;
            double pepper_random = 1.0 * std::rand() / RAND_MAX;

            bool is_salt = (salt_random < salt_probability_);
            bool is_pepper = (pepper_random < pepper_probability_);

            if (is_salt && is_pepper) {
                is_salt = (salt_random > pepper_random);
                is_pepper = (pepper_random > salt_random);
            }

            if (is_salt) {
                answer[height_i][width_i] = Pixel(0, 0, 0);
            } else if (is_pepper) {
                answer[height_i][width_i] = Pixel(255, 255, 255);
            } else {
                answer[height_i][width_i] = input[height_i][width_i];
            }
        }
    }
    return answer;
}
