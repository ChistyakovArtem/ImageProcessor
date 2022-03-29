cmake_minimum_required(VERSION 3.21)
project(Image_Processor)

set(CMAKE_CXX_STANDARD 14)

add_executable(Image_Processor main.cpp BaseFilter.cpp BaseFilter.h BMPOperator.cpp BMPOperator.h Pixel.cpp Pixel.h Image.cpp Image.h NegativeFilter.cpp NegativeFilter.h ConvolutionOperation.cpp ConvolutionOperation.h SharpFilter.cpp SharpFilter.h GrayScaleFilter.cpp GrayScaleFilter.h EdgeDetectionFilter.cpp EdgeDetectionFilter.h CropFilter.cpp CropFilter.h MedianBlurFilter.cpp MedianBlurFilter.h SaltAndPepperFilter.cpp SaltAndPepperFilter.h GaussianBlurFilter.cpp GaussianBlurFilter.h)
