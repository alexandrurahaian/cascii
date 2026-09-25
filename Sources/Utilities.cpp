//
// Created by alex on 9/24/26.
//
#include "../Headers/Utilities.h"
#include <string>
#include <algorithm>

std::string GetBinaryFromASCII(unsigned char asciiChar) {
    std::string result;
    result.reserve(8);

    int decimal = asciiChar;

    for (int i = 0; i < 8; i++) {
        int bit = decimal & 1;
        result += (bit == 1 ? '1' : '0');
        decimal >>= 1;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

std::string GetHexFromASCII(unsigned char asciiChar) {
    auto NibbleToHexChar = [](int nibble) {
        if (nibble < 10) {
            return '0' + nibble;
        } else {
            return 'A' + (nibble - 10);
        }
    };

    std::string result;
    result.reserve(2);

    int decimal = asciiChar;

    for (int i = 0; i < 2; i++) {
        int nibble = decimal & 0x0F;
        result += NibbleToHexChar(nibble);

        decimal >>= 4;
    }
    std::reverse(result.begin(), result.end());

    return result;
}