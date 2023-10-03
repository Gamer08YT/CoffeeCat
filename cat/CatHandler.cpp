//
// Created by Jan Heil on 03.10.2023.
//

#include <vector>
#include <thread>
#include "CatHandler.h"
#include "VirtualCat.h"
#include "../commands/CommandHandler.h"

std::vector<VirtualCat *> cats;

std::thread threadIO;

/**
 * Create new Cat.
 * @param nameIO
 */
void CatHandler::create(std::string nameIO) {
    cats.push_back(new VirtualCat(nameIO));
}

std::vector<VirtualCat *> CatHandler::getCats() {
    return cats;
}

void CatHandler::init() {
    threadIO = std::thread(handleCats);
    threadIO.detach();

    CommandHandler::println("Started NB Cat Thread.");
}

void CatHandler::handleCats() {
    while (true) {
        // Sleep for 1 Second to save CPU Bandwidth (Like Java?).
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        CommandHandler::println("SECOND");
    }
}
