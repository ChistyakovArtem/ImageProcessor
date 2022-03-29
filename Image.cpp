//
// Created by artem on 26.03.2022.
//

#include "Image.h"

Image::Image(const std::string& path) {
    ReadBMP(path);
}

void Image::ApplyFilter(const BaseFilter& f) {
    img_ = f.ApplyTransformation(img_);
}
