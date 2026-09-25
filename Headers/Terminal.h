//
// Created by alex on 9/20/26.
//

#ifndef CASCII_TERMINAL_H
#define CASCII_TERMINAL_H
#include "./OutColour.h"

struct Colour {
    RGBOutColour fRGB, bRGB;
    OutputColour fC = OutputColour::None, bC = OutputColour::None;
};

void error(const std::string& errorMsg, Colour clr = {});
void warn(const std::string& warnMsg, Colour clr = {});


#endif //CASCII_TERMINAL_H
