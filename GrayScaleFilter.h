//
// Created by artem on 26.03.2022.
//

#ifndef IMAGE_PROCESSOR_GRAYSCALEFILTER_H
#define IMAGE_PROCESSOR_GRAYSCALEFILTER_H

#include "BaseFilter.h"

class GrayScaleFilter : public BaseFilter {
public:
    GrayScaleFilter();
    std::vector<std::vector<Pixel> > ApplyTransformation(const std::vector<std::vector<Pixel> >& input) const override; // void
};


#endif //IMAGE_PROCESSOR_GRAYSCALEFILTER_H
