//
// Created by Jan Heil on 03.10.2023.
//

#ifndef COFFEECAT_HELPCOMMAND_H
#define COFFEECAT_HELPCOMMAND_H


#include <string>
#include "Command.h"

class HelpCommand : public Command {
    const char *invoke() override {
        return "help";
    }

    const char *description() override {
        return "Show this Help Page.";
    }

    void execute(std::vector<std::string> argsIO);
};


#endif //COFFEECAT_HELPCOMMAND_H
