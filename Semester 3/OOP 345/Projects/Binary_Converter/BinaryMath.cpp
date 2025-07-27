#include "BinaryMath.h"
#include "BinaryConverter.h"
#include <stdexcept>

std::string BinaryMath::add(const std::string& a, const std::string& b) {
    int result = BinaryConverter::binaryToDecimal(a) + BinaryConverter::binaryToDecimal(b);
    return BinaryConverter::decimalToBinary(result);
}

std::string BinaryMath::subtract(const std::string& a, const std::string& b) {
    int result = BinaryConverter::binaryToDecimal(a) - BinaryConverter::binaryToDecimal(b);
    if (result < 0) throw std::invalid_argument("Result is negative.");
    return BinaryConverter::decimalToBinary(result);
}