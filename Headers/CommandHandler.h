//
// Created by alex on 9/20/26.
//

#ifndef CASCII_COMMANDHANDLER_H
#define CASCII_COMMANDHANDLER_H

#include "./Commands.h"
#include <unordered_map>
#include <memory>

#include "Terminal.h"

#include <iostream>
inline std::unordered_map<std::string, std::unique_ptr<Command>> commands;

void RegisterCommand(const std::string& commandText, std::unique_ptr<Command> cmd);
void Execute(const std::string& commandText, const std::vector<std::string>& args);
inline bool IsValidCommand(const std::string& commandText) {
    return (commands.find(commandText) != commands.end());
}

#endif //CASCII_COMMANDHANDLER_H
