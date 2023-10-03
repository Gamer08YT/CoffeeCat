//
// Created by Jan Heil on 03.10.2023.
//

#include "FeedCommand.h"
#include "../cat/CatHandler.h"
#include "CommandHandler.h"

void FeedCommand::execute(std::vector<std::string> argsIO) {
    if (argsIO.size() > 0) {

    } else {
        CommandHandler::println("Available Items: Fish, Meat, Nuts");
        CommandHandler::println(description());
    }
}
