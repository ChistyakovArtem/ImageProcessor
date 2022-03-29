//
// Created by artem on 26.03.2022.
//

#ifndef IMAGE_PROCESSOR_EDGEDETECTIONFILTER_H
#define IMAGE_PROCESSOR_EDGEDETECTIONFILTER_H

#include "GrayScaleFilter.h"
#include "ConvolutionOperation.h"

class EdgeDetectionFilter : public GrayScaleFilter, ConvolutionOperation {
public:
    explicit EdgeDetectionFilter(uint8_t threshold);
    EdgeDetectionFilter();
    std::vector<std::vector<Pixel> > ApplyTransformation(const std::vector<std::vector<Pixel> >& input) const override; // void
private:
    uint8_t threshold_;
};


#endif //IMAGE_PROCESSOR_EDGEDETECTIONFILTER_H
