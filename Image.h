//
// Created by artem on 26.03.2022.
//

#ifndef IMAGE_PROCESSOR_IMAGE_H
#define IMAGE_PROCESSOR_IMAGE_H

#include "BMPOperator.h"
#include "Pixel.h"
#include "BaseFilter.h"
#include "NegativeFilter.h"
#include "SharpFilter.h"
#include "GrayScaleFilter.h"
#include "EdgeDetectionFilter.h"
#include "CropFilter.h"
#include "MedianBlurFilter.h"
#include "SaltAndPepperFilter.h"
#include "GaussianBlurFilter.h"

class Image : public BMPOperator, NegativeFilter, SharpFilter, EdgeDetectionFilter, CropFilter, MedianBlurFilter,
        SaltAndPepperFilter, GaussianBlurFilter {
    // GrayScaleFilter is in EdgeDetectionFilter
public:
    explicit Image(const std::string& path_to_input);
    void ApplyFilter(const BaseFilter& f);
};


#endif //IMAGE_PROCESSOR_IMAGE_H
