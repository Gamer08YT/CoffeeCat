#include <iostream>
#include "commands/CommandHandler.h"
#include "cat/CatHandler.h"

void handleCommand(std::string basicString);


int main() {
    setlocale(LC_ALL, "");
    std::cout << " _._     _,-'\"\"`-._\n"
                 "(,-.`._,'(       |\\`-/|\n"
                 "    `-.-' \\ )-`( , o o)\n"
                 "          `-    \\`_`\"'-" << std::endl;

    std::cout << "†";

    // Register Commands.
    CommandHandler::init();

    // Register Cat Thread.
    CatHandler::init();

    // Store last Console Line.
    std::string lineIO;

    // Read Console.
    while (std::getline(std::cin, lineIO)) {
        CommandHandler::handleCommand(lineIO);
    }

    return 0;
}


