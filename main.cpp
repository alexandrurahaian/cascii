#include <complex>
#include <iostream>
#include <vector>
#include "Headers/Commands.h"
#include "Headers/Terminal.h"
#include "Headers/CommandHandler.h"

#include <memory>

void OutputWatermark() {
    std::cout << R"(
              mm       mmmm       mmmm    mmmmmm    mmmmmm
             ####    m#""""#    ##""""#   ""##""    ""##""
  m#####m    ####    ##m       ##"          ##        ##
 ##"    "   ##  ##    "####m   ##           ##        ##
 ##         ######        "##  ##m          ##        ##
 "##mmmm#  m##  ##m  #mmmmm#"   ##mmmm#   mm##mm    mm##mm
   """""   ""    ""   """""       """"    """"""    """"""

                                                            )";
    std::cout << '\n';
}

std::vector<std::string> GetCmdArgs(const std::string& rawCommand) {
    std::vector<std::string> fetched;
    fetched.reserve(12);

    std::string argument;
    bool quotationFound = false;
    for (int i = 0; i < rawCommand.length(); i++) {
        const char& c = rawCommand[i];

        if (c == '"') {
            if (quotationFound && !argument.empty()) {
                quotationFound = false;
                fetched.emplace_back(argument);
                argument.clear();
                continue;
            }

            quotationFound = true;
            continue;
        }

        if (c == ' ') {
            if (!quotationFound && !argument.empty()) {
                fetched.emplace_back(argument);
                argument.clear();
                continue;
            }

            if (quotationFound && !argument.empty()) argument += c;
            continue;
        }

        argument += c;
    }

    if (!argument.empty()) fetched.emplace_back(argument);
    return fetched;
}

void RegisterAllCommands() {
    RegisterCommand("lookup", std::make_unique<Lookup>());
    RegisterCommand("table", std::make_unique<Table>());
    RegisterCommand("print", std::make_unique<Print>());
    RegisterCommand("getascii", std::make_unique<GetASCII>());
    RegisterCommand("help", std::make_unique<Help>());
}

int main() {
    OutputWatermark();
    RegisterAllCommands();
    std::string option;
    std::cout << "Run 'help' for a list of commands.\n";

    do {
        std::cout << ">>: ";
        std::getline(std::cin, option);
        if (option.empty()) continue;

        const std::vector<std::string>& args = GetCmdArgs(option);
        if (!args.empty() && IsValidCommand(args[0])) Execute(args[0], args);
        else if (option != "exit") warn("Invalid command: " + args[0]);
    }
    while (option != "exit");
    return 0;
}