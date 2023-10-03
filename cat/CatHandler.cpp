//
// Created by Jan Heil on 03.10.2023.
//

#include <vector>
#include <thread>
#include <random>
#include "CatHandler.h"
#include "VirtualCat.h"
#include "../commands/CommandHandler.h"

std::vector<VirtualCat *> cats;

std::thread threadIO;

VirtualCat *current = nullptr;

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

/**
 * @brief The CatHandler struct handles the creation, initialization, and processing of cats.
 *
 * The CatHandler struct provides functionality to create cats, retrieve the list of cats,
 * initialize the cat handler, handle the cats, and generate random long numbers.
 */

void CatHandler::handleCats() {
    while (true) {
        // Sleep for 1 Second to save CPU Bandwidth (Like Java?).
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        // Loop trough Cats and increment Values.
        for (VirtualCat *cat: CatHandler::getCats()) {
            // Check for Cat Health Status.
            if (cat->getHunger() > 0) {
                // Increment Cat Age.
                cat->setAge(cat->getAge() + 1);

                // Set Hunger of Cat.
                cat->setHunger(cat->getHunger() - randomLong(0.1, 2));
            } else {
                if (cat->isAlive()) {
                    // Print Death Message.
                    CommandHandler::print("Cat '");
                    CommandHandler::print(cat->getName());
                    CommandHandler::print("' has died (");
                    CommandHandler::print(std::to_string(cat->getAge()));
                    CommandHandler::println(" days old)    † R I P");

                    // Set Cat to Death.
                    cat->setAlive(false);
                }
            }
        }
    }
}

/**
 * @brief The CatHandler struct handles the creation, initialization, and processing of cats.
 *
 * The CatHandler struct provides functionality to create cats, retrieve the list of cats,
 * initialize the cat handler, handle the cats, and generate random long numbers.
 */

long CatHandler::randomLong(long minIO, long maxIO) {
    // Obtain a random number from hardware
    std::random_device rd;

    // Seed the generator
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long> distrib(minIO, maxIO);

    // Generate a random long
    return distrib(gen);
}

VirtualCat *CatHandler::getCat(std::basic_string<char> &basicString) {
    for (VirtualCat *cat: getCats()) {
        if (equalsIgnoreCase(cat->getName(), basicString)) {
            return cat;
        }
    }

    return nullptr;
}


bool CatHandler::equalsIgnoreCase(const std::string &a, const std::string &b) {
    if (a.length() != b.length()) {
        return false;
    }

    for (std::string::size_type i = 0; i < a.size(); ++i) {
        if (std::tolower(a[i]) != std::tolower(b[i])) {
            return false;
        }
    }

    return true;
}

void CatHandler::setCurrent(VirtualCat *cat) {
    current = cat;
}

VirtualCat * CatHandler::getCurrent() {
    return current;
}
