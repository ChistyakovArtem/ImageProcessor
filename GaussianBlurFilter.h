//
// Created by artem on 27.03.2022.
//

#ifndef IMAGE_PROCESSOR_GAUSSIANBLURFILTER_H
#define IMAGE_PROCESSOR_GAUSSIANBLURFILTER_H

#include "BaseFilter.h"
#include "ConvolutionOperation.h"

class GaussianBlurFilter : public BaseFilter, ConvolutionOperation {

public:
    explicit GaussianBlurFilter(double sigma);
    GaussianBlurFilter();
    std::vector<std::vector<Pixel> > ApplyTransformation(const std::vector<std::vector<Pixel> >& input) const override;
    std::vector<std::vector<double>> double_kernel_;

};


#endif //IMAGE_PROCESSOR_GAUSSIANBLURFILTER_H
