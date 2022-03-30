//
// Created by artem on 29.03.2022.
//

#ifndef IMAGE_PROCESSOR_TESTER_H
#define IMAGE_PROCESSOR_TESTER_H

#include "ConvolutionOperation.h"
#include "Pixel.h"

class Tester : public ConvolutionOperation {
public:
    Tester();
    bool test_convolution(int test_case);

};


#endif //IMAGE_PROCESSOR_TESTER_H
