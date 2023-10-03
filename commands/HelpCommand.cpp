//
// Created by Jan Heil on 03.10.2023.
//

#include "HelpCommand.h"
#include "CommandHandler.h"

void HelpCommand::execute(std::vector<std::string> argsIO) {
    // Loop trough Commands and Check or Execute.
    for (Command *commandIO: CommandHandler::getCommands()) {
        // Print Invoke with Description.
        CommandHandler::print(commandIO->invoke());
        CommandHandler::print(" -> ");
        CommandHandler::println(commandIO->description());
    }
}
