#include "Lua.h"

int main()
{
    return Lua::get().run_script("../src/lua/main.lua");
}