//
// Created by artem on 26.03.2022.
//

#ifndef IMAGE_PROCESSOR_BMPOPERATOR_H
#define IMAGE_PROCESSOR_BMPOPERATOR_H

#include <vector>
#include <string>
#include "Pixel.h"

class BMPOperator {
public:
    void ReadBMP(const std::string& path_to_input);
    void WriteBMP(const std::string& path_to_output);

    unsigned char* CreateBitmapFileHeader(int height, int stride) const;
    unsigned char* CreateBitmapInfoHeader(int height, int width);
    unsigned char info_[54];
    std::vector<std::vector<Pixel> > img_;


private:
    const int BYTES_PER_PIXEL = 3;
    const int FILE_HEADER_SIZE = 14;
    const int INFO_HEADER_SIZE = 40;
    const int INFO_BYTES_SIZE = 54;
};


#endif //IMAGE_PROCESSOR_BMPOPERATOR_H
