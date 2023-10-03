//
// Created by Jan Heil on 03.10.2023.
//

#ifndef COFFEECAT_ATTACHCOMMAND_H
#define COFFEECAT_ATTACHCOMMAND_H


#include <string>
#include "Command.h"

class AttachCommand : public Command {
    const char *invoke() override {
        return "attach";
    }

    const char *description() override {
        return "Attach to an Cat.";
    }

    void execute(std::vector<std::string> argsIO);
};


#endif //COFFEECAT_ATTACHCOMMAND_H
