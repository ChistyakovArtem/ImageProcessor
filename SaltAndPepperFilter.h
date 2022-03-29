//
// Created by artem on 27.03.2022.
//

#ifndef IMAGE_PROCESSOR_SALTANDPEPPERFILTER_H
#define IMAGE_PROCESSOR_SALTANDPEPPERFILTER_H

#include "BaseFilter.h"

class SaltAndPepperFilter : public BaseFilter {
public:
    SaltAndPepperFilter(double salt_probability, double pepper_probability);
    SaltAndPepperFilter();
    std::vector<std::vector<Pixel> > ApplyTransformation(const std::vector<std::vector<Pixel> >& input) const override;

private:
    double salt_probability_ = 0;
    double pepper_probability_ = 0;
};


#endif //IMAGE_PROCESSOR_SALTANDPEPPERFILTER_H
