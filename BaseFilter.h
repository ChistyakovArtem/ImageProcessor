//
// Created by artem on 22.03.2022.
//

#pragma once

#ifndef IMAGE_PROCESSOR_BASEFILTER_H
#define IMAGE_PROCESSOR_BASEFILTER_H

#include <vector>
#include <array>
#include "Pixel.h"


class BaseFilter {
public:
    BaseFilter();

    virtual std::vector<std::vector<Pixel> > ApplyTransformation(const std::vector<std::vector<Pixel> >& input) const; // void
};


#endif //IMAGE_PROCESSOR_BASEFILTER_H
