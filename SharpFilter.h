//
// Created by artem on 26.03.2022.
//

#ifndef IMAGE_PROCESSOR_SHARPFILTER_H
#define IMAGE_PROCESSOR_SHARPFILTER_H

#include "BaseFilter.h"
#include "ConvolutionOperation.h"

class SharpFilter : public BaseFilter, ConvolutionOperation {

public:
    SharpFilter();
    std::vector<std::vector<Pixel> > ApplyTransformation(const std::vector<std::vector<Pixel> >& input) const override;
};


#endif //IMAGE_PROCESSOR_SHARPFILTER_H
