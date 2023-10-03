//
// Created by Jan Heil on 03.10.2023.
//

#ifndef COFFEECAT_CATHANDLER_H
#define COFFEECAT_CATHANDLER_H


#include <string>
#include "VirtualCat.h"

class CatHandler {
public:
    static void create(std::string nameIO);

    static std::vector<VirtualCat *> getCats();

    static void init();

    static void handleCats();
};


#endif //COFFEECAT_CATHANDLER_H
