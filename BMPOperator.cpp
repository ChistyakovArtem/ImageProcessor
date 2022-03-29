//
// Created by artem on 26.03.2022.
//

#include "BMPOperator.h"

#include <iostream>

void BMPOperator::ReadBMP(const std::string &path_to_input) {
    const char *fileName = path_to_input.c_str();

    FILE* f = fopen(fileName, "rb");
    if (f == nullptr) {
        throw std::runtime_error("Input file '" + path_to_input + "' does not exist!");
    }
    fread(info_, sizeof(unsigned char), 54, f); // read the 54-byte header

    int width = *(int*)&info_[18];
    int height = *(int*)&info_[22];

    int widthInBytes = width * BYTES_PER_PIXEL;
    int paddingSize = (4 - (widthInBytes) % 4) % 4;
    auto* buffer = new unsigned char[3 * width];

    img_ = std::vector <std::vector<Pixel> >(height, std::vector<Pixel>(width, Pixel()));
    for(int height_i = 0; height_i < height; ++height_i) {
        fread(buffer, BYTES_PER_PIXEL, width, f);
        for (int width_i = 0; width_i < width; ++width_i) {
            img_[height_i][width_i] = Pixel(buffer[3 * width_i],
                                            buffer[3 * width_i + 1],
                                            buffer[3 * width_i + 2]); // rgb
        }
        fread(buffer, 1, paddingSize, f);
    }

    fclose(f);
}

void BMPOperator::WriteBMP(const std::string& path_to_output) {

    int image_height = static_cast<int>(img_.size());
    int image_width = static_cast<int>(img_[0].size());

    unsigned char padding[3] = {0, 0, 0};
    int widthInBytes = image_width * BYTES_PER_PIXEL;
    int paddingSize = (4 - (widthInBytes) % 4) % 4;
    int stride = (widthInBytes) + paddingSize;

    char* imageFileName = const_cast<char *> (path_to_output.c_str());
    FILE* imageFile = fopen(imageFileName, "wb");

    unsigned char* fileHeader = CreateBitmapFileHeader(image_height, stride);
    fwrite(fileHeader, 1, FILE_HEADER_SIZE, imageFile);

    unsigned char* infoHeader = CreateBitmapInfoHeader(image_height, image_width);
    fwrite(infoHeader, 1, INFO_HEADER_SIZE, imageFile);


    for (int height_i = 0; height_i < image_height; ++height_i) {
        unsigned char tmp[image_width][BYTES_PER_PIXEL];
        for (int width_i = 0; width_i < image_width; ++width_i) {
            tmp[width_i][0] = img_[height_i][width_i].red_;
            tmp[width_i][1] = img_[height_i][width_i].green_;
            tmp[width_i][2] = img_[height_i][width_i].blue_;
        }
        fwrite(tmp, BYTES_PER_PIXEL, image_width, imageFile);
        fwrite(padding, 1, paddingSize, imageFile);
    }

    fclose(imageFile);
}



unsigned char* BMPOperator::CreateBitmapFileHeader(int height, int stride) const {

    int fileSize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + (stride * height);

    static unsigned char fileHeader[] = {
            0,0,     /// signature
            0,0,0,0, /// image file size in bytes
            0,0,0,0, /// reserved
            0,0,0,0, /// start of pixel array
    };

    fileHeader[ 0] = (unsigned char)('B');
    fileHeader[ 1] = (unsigned char)('M');
    fileHeader[ 2] = (unsigned char)(fileSize      );
    fileHeader[ 3] = (unsigned char)(fileSize >>  8);
    fileHeader[ 4] = (unsigned char)(fileSize >> 16);
    fileHeader[ 5] = (unsigned char)(fileSize >> 24);
    fileHeader[10] = (unsigned char)(FILE_HEADER_SIZE + INFO_HEADER_SIZE);

    return fileHeader;
}

unsigned char* BMPOperator::CreateBitmapInfoHeader(int height, int width) {

    static unsigned char infoHeader[] = {
            0,0,0,0, /// header size
            0,0,0,0, /// image width
            0,0,0,0, /// image height
            0,0,     /// number of color planes
            0,0,     /// bits per pixel
            0,0,0,0, /// compression
            0,0,0,0, /// image size
            0,0,0,0, /// horizontal resolution
            0,0,0,0, /// vertical resolution
            0,0,0,0, /// colors in color table
            0,0,0,0, /// important color count
    };

    infoHeader[ 0] = (unsigned char)(INFO_HEADER_SIZE);
    infoHeader[ 4] = (unsigned char)(width      );
    infoHeader[ 5] = (unsigned char)(width >>  8);
    infoHeader[ 6] = (unsigned char)(width >> 16);
    infoHeader[ 7] = (unsigned char)(width >> 24);
    infoHeader[ 8] = (unsigned char)(height      );
    infoHeader[ 9] = (unsigned char)(height >>  8);
    infoHeader[10] = (unsigned char)(height >> 16);
    infoHeader[11] = (unsigned char)(height >> 24);
    infoHeader[12] = (unsigned char)(1);
    infoHeader[14] = (unsigned char)(BYTES_PER_PIXEL*8);

    return infoHeader;
}