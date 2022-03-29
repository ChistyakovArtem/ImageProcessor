//
// Created by artem on 26.03.2022.
//

#ifndef IMAGE_PROCESSOR_NEGATIVEFILTER_H
#define IMAGE_PROCESSOR_NEGATIVEFILTER_H

#include "BaseFilter.h"

class NegativeFilter : public BaseFilter {
public:
    NegativeFilter();
    std::vector<std::vector<Pixel> > ApplyTransformation(const std::vector<std::vector<Pixel> >& input) const override;
};


#endif //IMAGE_PROCESSOR_NEGATIVEFILTER_H
