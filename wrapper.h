//
// Created by Mekhail on 03.12.2020.
//

#pragma once

#include "definitions.h"

class Wrapper
{
public:

    template<typename Subject, class... Arguments>
    Wrapper(Subject *subject, int(Subject::*method)(Arguments...), const defNamesAndOrderArgs args)
    {
        if (args.size() != sizeof...(Arguments))
            return;

        for (auto& arg: args)
        {
            argNamesOrdered.push_back(arg.first);
            argsDefault.push_back(arg.second);
        }

        func = [this, subject, method](const std::vector<int>& argsVec) {
            return(callMethod(subject, method, argsVec, std::make_index_sequence<sizeof...(Arguments)>{}));
        };
    }

    int execute(const mapArgs& argsMap)
    {
        if (argsMap.size() != argNamesOrdered.size())
            return func(argsDefault);

        std::vector<int> argsFunc;
        for (auto& argName : argNamesOrdered)
        {
            auto it = argsMap.find(argName);
            if (it == argsMap.end())
                return func(argsDefault);

            argsFunc.push_back(it->second);
        }
        return func(argsFunc);
    }

private:

    template<typename Subject, typename Method, size_t... Is>
    int callMethod(Subject* subject, Method method,
                    const std::vector<int>& args, std::index_sequence<Is...>)
    {
        return((subject->*method)(args[Is]... ));
    }

    std::function<int(const std::vector<int>& argsVec)> func;
    std::vector<std::string> argNamesOrdered;
    std::vector<int> argsDefault;
};
