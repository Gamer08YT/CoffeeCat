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
        CommandHandler::print("Name: ");
        CommandHandler::println(cat->getName());

        // Print Age (Days)
        CommandHandler::print("Age (Days): ");
        CommandHandler::println(std::to_string(cat->getAge()));

        // Print Age (Years)
        CommandHandler::print("Age (Years): ");
        CommandHandler::println(std::to_string(cat->getAge() / 365));

        CommandHandler::print("Hunger: ");
        CommandHandler::println(std::to_string(cat->getHunger()));

        CommandHandler::println("===============================================");
    }
}
