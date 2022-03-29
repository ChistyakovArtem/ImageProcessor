//
// Created by artem on 27.03.2022.
//

#ifndef IMAGE_PROCESSOR_MEDIANBLURFILTER_H
#define IMAGE_PROCESSOR_MEDIANBLURFILTER_H

#include "BaseFilter.h"

class MedianBlurFilter : public BaseFilter {
public:
    explicit MedianBlurFilter(int receptor_field_size);
    MedianBlurFilter();
    std::vector<std::vector<Pixel> > ApplyTransformation(const std::vector<std::vector<Pixel> >& input) const override; // void
private:
    int receptor_field_size_ = 1;
};


#endif //IMAGE_PROCESSOR_MEDIANBLURFILTER_H
