//
// Created by alex on 9/20/26.
//
#include "../Headers/Commands.h"

#include <algorithm>

#include "../Headers/CommandHandler.h"
#include <string>
#include <vector>

#include <iostream>

#include "../Headers/Utilities.h"
constexpr static std::array<std::pair<uint8_t, std::string_view>, 34> UNPRINTABLE_ASCII_CHARS =
{
    {
        {0, "NULL"},
        {1, "START OF HEADING"},
        {2, "START OF TEXT"},
        {3, "END OF TEXT"},
        {4, "END OF TRANSMISSION"},
        {5, "ENQUIRY"},
        {6, "ACKNOWLEDGE"},
        {7, "BELL"},
        {8, "BACKSPACE"},
        {9, "HORIZONTAL TAB"},
        {10, "LINE FEED"},
        {11, "VERTICAL TAB"},
        {12, "FORM FEED"},
        {13, "CARRIAGE RETURN"},
        {14, "SHIFT OUT"},
        {15, "SHIFT IN"},
        {16, "DATA LINK ESCAPE"},
        {17, "DEVICE CONTROL 1"},
        {18, "DEVICE CONTROL 2"},
        {19, "DEVICE CONTROL 3"},
        {20, "DEVICE CONTROL 4"},
        {21, "NEGATIVE ACKNOWLEDGE"},
        {22, "SYNCHRONOUS IDLE"},
        {23, "END OF TRANSMISSION BLOCK"},
        {24, "CANCEL"},
        {25, "END OF MEDIUM"},
        {26, "SUBSTITUTE"},
        {27, "ESCAPE"},
        {28, "FILE SEPARATOR"},
        {29, "GROUP SEPARATOR"},
        {30, "RECORD SEPARATOR"},
        {31, "UNIT SEPARATOR"},
        {32, "SPACE"},
        {33, "DEL"}
    }
};

void Help::run(const std::vector<std::string> &args) {
    for (const auto& [name, cmd] : commands) {
        if (!cmd) continue;
        setFOutColour(name, OutputColour::BrightBlue, {}, true);
        std::cout << cmd->info() << '\n';
    }
}

void Lookup::run(const std::vector<std::string> &args) {
    size_t argc = args.size();
    if (argc < 2) {
        error("Please provide a character to lookup.");
        return;
    }

    char toLookup = args[1][0];
    if (toLookup >= 0 && toLookup <= 127) {
        std::string outStr = "[LOOKUP RESULT] (";
        outStr += (char)toLookup;
        outStr += "): ";

        std::string decimalOut = " - DECIMAL: ";
        decimalOut += std::to_string(toLookup);
        decimalOut += '\n';

        setFOutColour(outStr, OutputColour::BrightBlue);
        setFOutColour(("BIN: " + GetBinaryFromASCII(toLookup)), OutputColour::Blue);
        setFOutColour((" - HEX: " + GetHexFromASCII(toLookup)), OutputColour::Yellow);
        setFOutColour(decimalOut, OutputColour::Red, {}, true);
    }
    else error("Invalid character provided.");
}

void Table::run(const std::vector<std::string> &args) {
    setOutColour(" --- ASCII TABLE ---", OutputColour::Black, OutputColour::Green, {}, {}, false, 1);

    for (int i = 0; i <= 32; i++) {
        std::cout << "[" << i << "]: [" << UNPRINTABLE_ASCII_CHARS[i].second << "]\n";
    }

    for (int i = 33; i <= 126; i++) {
        std::cout << "[" << i << "]: " << static_cast<char>(i) << '\n';
    }

    std::cout << "[127]: [DEL]\n";

    resetColour();
    std::cout << '\n';
}

void Print::run(const std::vector<std::string> &args) {
    if (args.size() < 2) {
        error("Too few arguments.");
        return;
    }

    int number;
    try {
        number = std::stoi(args[1]);
    }
    catch (...) {
        error("Could not convert " + args[1] + " to number.");
        return;
    }

    if (number >= 0 && number <= 127) {
        std::cout << static_cast<char>(number) << '\n';
    }
    else error("Invalid ASCII number (0 <= number <= 127): " + args[1]);
}

void GetASCII::run(const std::vector<std::string> &args) {
    if (args.size() < 2) {
        error("Too few arguments.");
        return;
    }

    const std::string& iterateStr = args[1];
    if (iterateStr.empty()) {
        warn("Provided string was empty.");
        return;
    }

    size_t len = iterateStr.length();
    for (int i = 0; i < len; i++) {
        std::cout << static_cast<int>(iterateStr[i]);
        if (i < len - 1) std::cout << ' ';
    }
    std::cout << '\n';
}
