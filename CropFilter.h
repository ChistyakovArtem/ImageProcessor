//
// Created by artem on 26.03.2022.
//

#ifndef IMAGE_PROCESSOR_CROPFILTER_H
#define IMAGE_PROCESSOR_CROPFILTER_H

#include "BaseFilter.h"

class CropFilter : public BaseFilter {
public:
    CropFilter(int crop_height, int crop_width);

    CropFilter();

    std::vector<std::vector<Pixel> > ApplyTransformation(const std::vector<std::vector<Pixel> >& input) const override; // void
private:
    int crop_height_;
    int crop_width_;
};


#endif //IMAGE_PROCESSOR_CROPFILTER_H
