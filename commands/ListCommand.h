//
// Created by Jan Heil on 03.10.2023.
//

#ifndef COFFEECAT_LISTCOMMAND_H
#define COFFEECAT_LISTCOMMAND_H


#include <string>
#include "Command.h"

class ListCommand : public Command {
public:
    const char *invoke() override {
        return "list";
    }

    const char *description() override {
        return "List created Cats";
    }

    void execute(std::vector<std::string> argsIO);
};


#endif //COFFEECAT_LISTCOMMAND_H
