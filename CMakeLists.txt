cmake_minimum_required(VERSION 3.27)
project(CoffeeCat)

set(CMAKE_CXX_STANDARD 23)

add_executable(CoffeeCat main.cpp
        commands/Command.h
        commands/Command.cpp
        commands/ListCommand.h
        commands/ListCommand.cpp
        commands/HelpCommand.cpp
        commands/HelpCommand.h
        commands/CommandHandler.cpp
        commands/CommandHandler.h
        commands/CreateCommand.cpp
        commands/CreateCommand.h
        cat/VirtualCat.cpp
        cat/VirtualCat.h
        cat/CatHandler.cpp
        cat/CatHandler.h
        commands/FeedCommand.cpp
        commands/FeedCommand.h
        commands/AttachCommand.cpp
        commands/AttachCommand.h)
