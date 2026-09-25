//
// Created by alex on 9/20/26.
//

#ifndef CASCII_COMMANDS_H
#define CASCII_COMMANDS_H
#include "../Classes/Command.h"

class Lookup : public Command {
public:
    void run(const std::vector<std::string> &args) override;
    [[nodiscard]] const std::string_view info() const override {return " [char] --> searches for the specified character in the ASCII table and returns it's decimal, hex, and binary equivalent.";}
};

class Table : public Command {
public:
    void run(const std::vector<std::string> &args) override;
    [[nodiscard]] const std::string_view info() const override {return " --> displays the whole ascii table.";}
};

class Help : public Command {
public:
    void run(const std::vector<std::string> &args) override;
    [[nodiscard]] const std::string_view info() const override {return " --> displays a list of all of the commands.";}
};

class Print : public Command {
public:
    void run(const std::vector<std::string> &args) override;
    [[nodiscard]] const std::string_view info() const override {return " [decimal] --> prints out the ascii char in the console.";}
};

class GetASCII : public Command {
    void run(const std::vector<std::string> &args) override;
    [[nodiscard]] const std::string_view info() const override {return " [string] --> gets the ASCII character codes of each letter in the string.";}
};

#endif //CASCII_COMMANDS_H
