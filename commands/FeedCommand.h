//
// Created by Jan Heil on 03.10.2023.
//

#ifndef COFFEECAT_FEEDCOMMAND_H
#define COFFEECAT_FEEDCOMMAND_H


#include <string>
#include "Command.h"

class FeedCommand : public Command {
    const char *invoke() override {
        return "feed";
    }

    const char *description() override {
        return "Feed attached Cat /feed <Item>";
    }

    void execute(std::vector<std::string> argsIO);
};


#endif //COFFEECAT_FEEDCOMMAND_H
