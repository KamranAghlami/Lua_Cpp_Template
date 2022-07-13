#include "LuaInterpreter.h"

int main()
{
    return LuaInterpreter::get().run_script("../src/lua/main.lua");
}