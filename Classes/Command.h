//
// Created by alex on 9/20/26.
//

#ifndef CASCII_COMMAND_H
#define CASCII_COMMAND_H
#include <vector>
#include <string>

class Command {
public:
    virtual ~Command() = default;
    virtual void run(const std::vector<std::string>& args) = 0;
    virtual const std::string_view info() const = 0;
};


#endif //CASCII_COMMAND_H
