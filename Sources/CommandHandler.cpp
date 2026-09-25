//
// Created by alex on 9/20/26.
//
#include "../Headers/CommandHandler.h"
#include "../Headers/Terminal.h"
#include "../Classes/Command.h"

void RegisterCommand(const std::string& commandText, std::unique_ptr<Command> cmd)
{
    if (commands.find(commandText) == commands.end()) {
        commands.emplace(commandText, std::move(cmd));
    }
    else error(("Failed to register command: " + commandText + " (command already registered)!"));
}
void Execute(const std::string& commandText, const std::vector<std::string>& args) {
    auto it = commands.find(commandText);
    if (it != commands.end()) {
        if (it->second) {
            it->second->run(args);
        } else {
            error("Command pointer is null: " + commandText);
        }
    } else {
        error("Invalid command: " + commandText);
    }
}