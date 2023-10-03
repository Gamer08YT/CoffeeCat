//
// Created by Jan Heil on 03.10.2023.
//

#include "AttachCommand.h"
#include "CommandHandler.h"
#include "../cat/CatHandler.h"

void AttachCommand::execute(std::vector<std::string> argsIO) {
    if (argsIO.size() > 0) {
        // Get Cat by Name.
        VirtualCat *catIO = CatHandler::getCat(argsIO[0]);

        if (catIO != nullptr) {
            CatHandler::setCurrent(catIO);
            CommandHandler::print("Attached to Cat '");
            CommandHandler::print(argsIO[0]);
            CommandHandler::println("'.");
        } else {
            CommandHandler::print("Can't find Cat '");
            CommandHandler::print(argsIO[0]);
            CommandHandler::println("'.");
        }
    } else
        CommandHandler::println(description());
}
