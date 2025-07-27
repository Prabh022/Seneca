#include "BinaryConverter.h"
#include <stdexcept>
#include <cmath>
#include <algorithm>

std::string BinaryConverter::decimalToBinary(int decimal) {
    if (decimal < 0) throw std::invalid_argument("Negative numbers not supported.");
    if (decimal == 0) return "0";

    std::string binary = "";
    while (decimal > 0) {
        binary = std::to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}

int BinaryConverter::binaryToDecimal(const std::string& binary) {
    if (!isValidBinary(binary)) throw std::invalid_argument("Invalid binary string.");
    int decimal = 0;
    for (size_t i = 0; i < binary.size(); ++i)
        if (binary[binary.size() - 1 - i] == '1')
            decimal += static_cast<int>(std::pow(2, i));
    return decimal;
}

bool BinaryConverter::isValidBinary(const std::string& binary) {
    return !binary.empty() &&
        std::all_of(binary.begin(), binary.end(), [](char c) { return c == '0' || c == '1'; });
}