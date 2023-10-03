//
// Created by Jan Heil on 03.10.2023.
//

#ifndef COFFEECAT_COMMANDHANDLER_H
#define COFFEECAT_COMMANDHANDLER_H


#include <string>
#include "Command.h"

class CommandHandler {

public:
    static void init();

    static void handleCommand(std::string dataIO);

    static void println(std::string basicString);

    static std::vector<std::string> split(std::string basicString, char i);

    static void addCommand(Command *commandIO);

    static std::vector<Command *> getCommands();

    static void print(std::basic_string<char> string);
};


#endif //COFFEECAT_COMMANDHANDLER_H
