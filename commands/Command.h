//
// Created by Jan Heil on 03.10.2023.
//

#ifndef COFFEECAT_COMMAND_H
#define COFFEECAT_COMMAND_H


#include <vector>

class Command {
public:
    virtual const char *invoke() {
        return "unset";
    }

    virtual const char *description() {
        return "Nothing set :(";
    }

    virtual void execute(std::vector<std::string> argsIO);
};


#endif //COFFEECAT_COMMAND_H
