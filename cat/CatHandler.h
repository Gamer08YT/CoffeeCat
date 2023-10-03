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

    static long randomLong(long minIO, long maxIO);

    static bool equalsIgnoreCase(const std::string &a, const std::string &b);

    static VirtualCat *getCat(std::basic_string<char> &basicString);


    static void setCurrent(VirtualCat *cat);

    static VirtualCat * getCurrent();
};


#endif //COFFEECAT_CATHANDLER_H
