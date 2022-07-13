#include "Lua.h"

int main()
{
    Lua::get().run_string("print(\"Hello, Lua!\")");

    return Lua::get().run_script("../src/lua/main.lua");
}