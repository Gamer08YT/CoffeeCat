//
// Created by Jan Heil on 03.10.2023.
//

#include <algorithm>
#include "FeedCommand.h"
#include "../cat/CatHandler.h"
#include "CommandHandler.h"

/**
 * @brief Executes the feed command.
 *
 * This function is called when the feed command is invoked. It takes a vector of strings as input arguments.
 * If a current cat is attached, it checks the first argument and feeds the cat accordingly.
 * The available items are fish, meat, and nuts, which have different saturation values.
 * The saturation value is added to the cat's hunger level.
 * If the first argument does not match any available items, an error message is printed.
 * If no arguments are provided, the available items and a description of the command are printed.
 * If no cat is currently attached, an error message is printed.
 *
 * @param argsIO A vector of strings representing the input arguments.
 */

void FeedCommand::execute(std::vector<std::string> argsIO) {
    VirtualCat *cat = CatHandler::getCurrent();

    if (cat != nullptr) {
        if (argsIO.size() > 0) {
            int saturation = 0;
            std::string first_argument = argsIO[0];

            std::transform(first_argument.begin(), first_argument.end(), first_argument.begin(),
                           [](unsigned char c) { return std::tolower(c); });


            if (first_argument == "fish") {
                saturation = 10;
            } else if (first_argument == "meat") {
                saturation = 15;
            } else if (first_argument == "nuts") {
                saturation = 1;
            } else {
                CommandHandler::println("Can't find Item...");
            }

            if (saturation != 0) {
                cat->setHunger(cat->getHunger() + saturation);

                CommandHandler::println("Successfully fed your Cat.");
            }
        } else {
            CommandHandler::println("Available Items: Fish, Meat, Nuts");
            CommandHandler::println(description());
        }
    } else CommandHandler::println("Please attach to an Cat with /attach <Name>");
}
