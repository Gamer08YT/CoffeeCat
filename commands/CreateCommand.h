//
// Created by Jan Heil on 03.10.2023.
//

#ifndef COFFEECAT_CREATECOMMAND_H
#define COFFEECAT_CREATECOMMAND_H


#include <string>
#include "Command.h"

class CreateCommand : public Command {
public:
    const char *invoke() override {
        return "create";
    }

    const char *description() override {
        return "Create a new Cat /create <Name>.";
    }

    void execute(std::vector<std::string> argsIO) override;
};


#endif //COFFEECAT_CREATECOMMAND_H
