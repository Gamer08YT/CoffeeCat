//
// Created by Jan Heil on 03.10.2023.
//

#include <iostream>
#include <sstream>
#include "CommandHandler.h"
#include "HelpCommand.h"
#include "ListCommand.h"
#include "CreateCommand.h"
#include "FeedCommand.h"
#include "AttachCommand.h"


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<Command *> commands;

void CommandHandler::handleCommand(std::string dataIO) {
    bool foundIO = false;

    if (dataIO.rfind("/", 0) == 0) { //Equivalent to startsWith
        dataIO.erase(0, 1); //Remove the first character '/'

        std::vector<std::string> splitIO = CommandHandler::split(dataIO, ' '); // Assuming character delimiter

        for (auto &commandIO: CommandHandler::getCommands()) { //Assuming getCommands returns std::vector<Command*>
            // Transform to lower case before comparing
            std::string cmd = splitIO[0];
            std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);

            std::string invoke = commandIO->invoke();
            std::transform(invoke.begin(), invoke.end(), invoke.begin(), ::tolower);

            // Check if command matches invoke function
            if (cmd.compare(invoke) == 0) {
                // Delete first Vector Item.
                if (!splitIO.empty())
                    splitIO.erase(splitIO.begin());

                print("Args: ");     //Assuming there's a print function
                println(std::to_string(splitIO.size()));  //Assuming there's a println function

                // Execute command
                commandIO->execute(splitIO);

                foundIO = true;
            }
        }

        // Print Error Message.
        if (!foundIO) {
            CommandHandler::print("Can't find command, use /help to display all commands.");
            CommandHandler::println(dataIO);
        }
    }
}

void CommandHandler::println(std::string basicString) {
    std::cout << basicString << std::endl;
}

void CommandHandler::print(std::basic_string<char> string) {
    std::cout << string;
}

std::vector<std::string> CommandHandler::split(std::string str, char delimiter) {
    std::vector<std::string> internal;
    std::stringstream ss(str); // Turn the string into a stream.
    std::string tok;

    while (getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}

void CommandHandler::init() {
    CommandHandler::addCommand(new HelpCommand());
    CommandHandler::addCommand(new ListCommand());
    CommandHandler::addCommand(new CreateCommand());
    CommandHandler::addCommand(new FeedCommand());
    CommandHandler::addCommand(new AttachCommand());
}

/**
 * Add Command to Vector.
 * @param commandIO
 */
void CommandHandler::addCommand(Command *commandIO) {
    // Print Debug Message.
    //print("Added Command ");
    //println(commandIO->invoke());

    // Push Command into Vector.
    commands.push_back(commandIO);
}

std::vector<Command *> CommandHandler::getCommands() {
    return commands;
}

