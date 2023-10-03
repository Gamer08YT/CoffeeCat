//
// Created by Jan Heil on 03.10.2023.
//

#include "CreateCommand.h"
#include "CommandHandler.h"
#include "../cat/CatHandler.h"

void CreateCommand::execute(std::vector<std::string> argsIO) {
    // Create new Cat.
    CatHandler::create(argsIO[0]);

    CommandHandler::print("Cat '");
    CommandHandler::print(argsIO[0]);
    CommandHandler::println("' was successfully created.");
}
