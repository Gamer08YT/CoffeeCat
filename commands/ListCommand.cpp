//
// Created by Jan Heil on 03.10.2023.
//

#include "ListCommand.h"
#include "../cat/VirtualCat.h"
#include "../cat/CatHandler.h"
#include "CommandHandler.h"

void ListCommand::execute(std::vector<std::string> argsIO) {
    // Loop trough Cats.
    for (VirtualCat *cat: CatHandler::getCats()) {
        // Print Name with Age.
        CommandHandler::print(cat->getName());
        CommandHandler::print(" - ");
        CommandHandler::println(std::to_string(cat->getAge()));
    }
}
