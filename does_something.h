//
// Created by Mekhail on 03.12.2020.
//

#pragma once

#include "definitions.h"

class DoesSomething
{
public:

    int do0()
    {
        std::cout << "do0 args: "<< "empty" << std::endl;
        return 0;
    };

    int do1(int a)
    {
        std::cout << "do1 args: "<< a << std::endl;
        return a;
    }

    int do2(int a, int b)
    {
        std::cout << "do2 args: "<< a << " " << b << std::endl;
        return a+b;
    }
};
