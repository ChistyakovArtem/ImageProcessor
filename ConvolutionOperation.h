//
// Created by artem on 26.03.2022.
//

#ifndef IMAGE_PROCESSOR_CONVOLUTIONOPERATION_H
#define IMAGE_PROCESSOR_CONVOLUTIONOPERATION_H


#include <cstdint>
#include <vector>
#include "Pixel.h"

class ConvolutionOperation {
public:
    ConvolutionOperation();
    virtual std::vector<std::vector<Pixel> > ApplyConvolution(const std::vector<std::vector<Pixel> >& input) const;
private:
protected:
    std::vector<std::vector<int16_t>> kernel_;
    int kernel_height;
    int kernel_width;
};


#endif //IMAGE_PROCESSOR_CONVOLUTIONOPERATION_H
