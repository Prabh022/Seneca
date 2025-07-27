#ifndef BINARY_CONVERTER_H
#define BINARY_CONVERTER_H

#include <string>

class BinaryConverter {
public:
    static std::string decimalToBinary(int decimal);
    static int binaryToDecimal(const std::string& binary);
    static bool isValidBinary(const std::string& binary);
};

#endif