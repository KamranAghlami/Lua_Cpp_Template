#pragma once

#include <string>

extern "C"
{
#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"
}

class LuaInterpreter
{
public:
    static LuaInterpreter &get()
    {
        static LuaInterpreter interpreter;

        return interpreter;
    }

    int run_script(const std::string &path)
    {
        int ret = luaL_dofile(mp_state, path.c_str());

        if (ret)
            printf("%s\n", lua_tostring(mp_state, -1));

        return ret;
    }

private:
    LuaInterpreter() : mp_state(luaL_newstate())
    {
        luaL_openlibs(mp_state);
    }

    ~LuaInterpreter()
    {
        lua_close(mp_state);
    }

    lua_State *mp_state;
};