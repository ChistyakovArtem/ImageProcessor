#include "BMPOperator.h"
#include "BaseFilter.h"
#include "Image.h"
#include "GrayScaleFilter.h"
#include "EdgeDetectionFilter.h"

#include <iostream>

namespace Errors {
    namespace Crop {
        int GetNewHeight(char* input) {
            int new_height = 0;

            try {
                new_height = std::stoi(input);
            } catch (const std::out_of_range& e) {
                throw std::out_of_range("New height must be integer in [1, 65536) interval,"
                                        "got '" + std::string(input) + "'");
            } catch (const std::invalid_argument& e) {
                throw std::invalid_argument("New height must be integer (in [1, 65536)) interval,"
                                            " got '" + std::string(input) + "'");
            } catch (const std::logic_error& e1) {
                throw std::logic_error("Crop operation require 2 parameters (new height&width),"
                                       " got 0 parameters");
            }
            if ((new_height < 1) | (new_height > 65536)) {
                throw std::out_of_range("New height must be in [1, 65536) interval,"
                                        "got '" + std::to_string(new_height) + "'");
            }

            return new_height;
        }
        int GetNewWidth(char* input_prev, char* input) {
            int new_width = 0;
            try {
                new_width = std::stoi(input);
            } catch (const std::out_of_range& e) {
                throw std::out_of_range("New width must be integer in [1, 65536) interval,"
                                        "got '" + std::string(input) + "'");
            } catch (const std::invalid_argument& e) {
                throw std::invalid_argument("New width must be integer (in [1, 65536)) interval,"
                                            " got '" + std::string(input) + "'");
            } catch (const std::logic_error& e1) {
                throw std::logic_error("Crop operation require 2 parameters (new height&width),"
                                       " got 1 parameter - '" + std::string(input_prev) + "'");
            }
            if ((new_width < 1) | (new_width > 65536)) {
                throw std::out_of_range("New width must be in [1, 65536) interval,"
                                        "got '" + std::to_string(new_width) + "'");
            }
            return new_width;
        }
    }
    int GetThreshold(char* input) {
        int threshold = 0;
        try {
            threshold = std::stoi(input);
        } catch (const std::out_of_range& e) {
            throw std::out_of_range("Threshold must be integer in [0, 255] interval,"
                                    "got '" + std::string(input) + "'");
        } catch (const std::invalid_argument& e) {
            throw std::invalid_argument("Threshold must be integer in [0, 255] interval,"
                                        " got '" + std::string(input) + "'");
        } catch (const std::logic_error& e) {
            throw std::logic_error("Edge detection operation require 1 parameter ((edge) threshold),"
                                   " got 0 parameters");
        }

        if ((threshold < 0) | (threshold > 255)) {
            throw std::invalid_argument("Threshold must be integer in [0, 255] interval,"
                                        " got '" + std::string(input) + "'");
        }
        return threshold;
    }
    int GetReceptorFieldSize(char* input) {
        int receptive_field_size = 0;
        try {
            receptive_field_size = std::stoi(input);
        } catch (const std::out_of_range& e) {
            throw std::out_of_range("Receptor field size must be odd integer in [1, 13] interval, "
                                    "got '" + std::string(input) + "'");
        } catch (const std::invalid_argument& e) {
            throw std::invalid_argument("Receptor field size must be integer, got '" +
                                        std::string(input) + "'");
        } catch (const std::logic_error& e) {
            throw std::logic_error("Median blurring operation require 1 parameter (receptive_field_size), "
                                   " got 0 parameters");
        }
        if (receptive_field_size % 2 == 0) {
            throw std::invalid_argument("Receptor field must be odd, got '" + std::string(input) + "'");
        }
        if (receptive_field_size > 13) {
            throw std::invalid_argument("Receptor field size must be odd integer in [1, 13] interval, "
                                        "got '" + std::string(input) + "'");
        }
        return receptive_field_size;
    }
    namespace Salt_n_pepper {
        double GetSaltRate(char* input) {
            double salt_rate = 0.0;

            try {
                salt_rate = std::stod(input);
            } catch (const std::out_of_range& e) {
                throw std::out_of_range("Salt rate must be in [0, 1] interval, "
                                        "got '" + std::string(input) + "'");
            } catch (const std::invalid_argument& e) {
                throw std::out_of_range("Salt rate must be in [0, 1] interval, "
                                        "got '" + std::string(input) + "'");
            } catch (const std::logic_error& e1) {
                throw std::logic_error("Salt_n_pepper require 2 parameters (salt_rate&pepper_rate), "
                                       "got 0 parameters");
            }
            if ((salt_rate < 0.0) | (salt_rate > 1.0)) {
                throw std::out_of_range("Salt rate must be in [0, 1] interval, "
                                        "got '" + std::to_string(salt_rate) + "'");
            }

            return salt_rate;
        }
        double GetPepperRate(char* input_prev, char* input) {
            double pepper_rate = 0.0;
            try {
                pepper_rate = std::stod(input);
            } catch (const std::out_of_range& e) {
                throw std::out_of_range("Pepper rate must be in [0, 1] interval, "
                                        "got '" + std::string(input) + "'");
            } catch (const std::invalid_argument& e) {
                throw std::invalid_argument("Pepper rate must be in [0, 1] interval, "
                                            " got '" + std::string(input) + "'");
            } catch (const std::logic_error& e1) {
                throw std::logic_error("Salt_n_pepper require 2 parameters (salt_rate&pepper_rate), "
                                       " got 1 parameter - '" + std::string(input_prev) + "'");
            }
            if ((pepper_rate < 0.0) | (pepper_rate > 1.0)) {
                throw std::out_of_range("Pepper rate must be in [0, 1] interval, "
                                        "got '" + std::to_string(pepper_rate) + "'");
            }
            return pepper_rate;
        }
    }
    double GetSigma(char* input) {
        double sigma = 0;
        try {
            sigma = std::stod(input);
        } catch (const std::out_of_range& e) {
            throw std::out_of_range("Sigma must be in [0, 15] interval,"
                                    "got '" + std::string(input) + "'");
        } catch (const std::invalid_argument& e) {
            throw std::out_of_range("Sigma must be in [0, 15] interval,"
                                    "got '" + std::string(input) + "'");
        } catch (const std::logic_error& e) {
            throw std::logic_error("Edge detection operation require 1 parameter ((edge) threshold),"
                                   " got 0 parameters");
        }

        if ((sigma < 0) | (sigma > 15)) {
            throw std::out_of_range("Sigma must be in [0, 15] interval,"
                                    "got '" + std::string(input) + "'");
        }
        return sigma;
    }
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "Reference information in github.com/ChistyakovArtem/ImageProcessor" << std::endl;
        return 0;
    }

    std::string path_to_input = argv[1];
    std::string input_format = path_to_input.substr(path_to_input.size() - 4, 4);
    if (input_format != ".bmp") {
        throw std::runtime_error("Expected input file in .bmp format, got file '" +
        path_to_input + "' in '" + input_format + "' format");
    }

    std::string path_to_output = argv[2];
    std::string output_format = path_to_output.substr(path_to_output.size() - 4, 4);
    if (output_format != ".bmp") {
        throw std::runtime_error("Expected output file in .bmp format, got file '" +
                                 path_to_output + "' in '" + output_format + "' format");
    }
    Image img(path_to_input);

    for (int i = 3; i < argc; ++i) {
        std::string new_command(argv[i]);
        if (new_command == "-neg") {
            img.ApplyFilter(NegativeFilter());
        } else if (new_command == "-gs") {
            img.ApplyFilter(GrayScaleFilter());
        } else if (new_command == "-sharp"){
            img.ApplyFilter(SharpFilter());
        } else if (new_command == "-crop") {
            int new_height = Errors::Crop::GetNewHeight(argv[i + 1]);
            int new_width = Errors::Crop::GetNewWidth(argv[i + 1], argv[i + 2]);

            i += 2;
            img.ApplyFilter(CropFilter(new_height, new_width));
        } else if (new_command == "-edge") {
            int threshold = Errors::GetThreshold(argv[i + 1]);

            i += 1;
            img.ApplyFilter(EdgeDetectionFilter(threshold));
        } else if (new_command == "-medianblur") {
            int receptive_field_size = Errors::GetReceptorFieldSize(argv[i + 1]);

            i += 1;
            img.ApplyFilter(MedianBlurFilter(receptive_field_size));
        } else if (new_command == "-salt_n_pepper") {

            double salt_rate = Errors::Salt_n_pepper::GetSaltRate(argv[i + 1]);
            double pepper_rate = Errors::Salt_n_pepper::GetPepperRate(argv[i + 1], argv[i + 2]);

            i += 2;
            img.ApplyFilter(SaltAndPepperFilter(salt_rate, pepper_rate));
        } else if (new_command == "-blur") {
            double sigma = Errors::GetSigma(argv[i + 1]);

            i += 1;
            img.ApplyFilter(GaussianBlurFilter(sigma));
        } else {
            throw std::invalid_argument("Unacceptable command, got '" + new_command +
            "', run program without arguments to get help");
        }
    }

    img.WriteBMP(path_to_output);
    return 0;
}
