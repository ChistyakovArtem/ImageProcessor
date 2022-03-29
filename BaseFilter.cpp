//
// Created by artem on 22.03.2022.
//

#include "BaseFilter.h"


BaseFilter::BaseFilter() = default;

std::vector<std::vector<Pixel> > BaseFilter::ApplyTransformation(const std::vector<std::vector<Pixel> >& input) const {
    return input;
}
