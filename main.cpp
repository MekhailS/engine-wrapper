#include "definitions.h"

#include "does_something.h"
#include "wrapper.h"
#include "engine.h"

int main()
{
    DoesSomething heDoesSomething;

    Wrapper wrapper(&heDoesSomething, &DoesSomething::do2, {{"arg1", 0}, {"arg2", 0}});

    Engine engine;

    engine.registerCommand(&wrapper, "command1");

    std::cout << engine.execute("command1", {{"arg1", 1}, {"arg2", 10}}) << std::endl;
}