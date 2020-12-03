//
// Created by Mekhail on 03.12.2020.
//

#pragma once

#include "definitions.h"
#include "wrapper.h"

class Engine
{
public:

    bool registerCommand(Wrapper* wrapper, std::string cmdName)
    {
        if (commands.find(cmdName) != commands.end())
            return false;

        commands[cmdName] = wrapper;
        return true;
    }

    auto execute(std::string cmdName, const mapArgs& argsMap)
    {
        auto it = commands.find(cmdName);
        if (it == commands.end())
            return 0;

        return (it->second->execute(argsMap));
    }

private:

    std::map<std::string, Wrapper*> commands;
};
