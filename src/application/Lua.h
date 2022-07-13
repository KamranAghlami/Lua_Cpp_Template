#pragma once

#include <string>

extern "C"
{
#include "lauxlib.h"
#include "lua.h"
#include "lualib.h"
}

class Lua
{
public:
    static Lua &get()
    {
        static Lua lua;

        return lua;
    }

    int run_string(const std::string &str)
    {
        int ret = luaL_dostring(mp_state, str.c_str());

        if (ret)
            printf("%s\n", lua_tostring(mp_state, -1));

        return ret;
    }

    int run_script(const std::string &path)
    {
        int ret = luaL_dofile(mp_state, path.c_str());

        if (ret)
            printf("%s\n", lua_tostring(mp_state, -1));

        return ret;
    }

private:
    Lua() : mp_state(luaL_newstate())
    {
        luaL_openlibs(mp_state);
    }

    ~Lua()
    {
        lua_close(mp_state);
    }

    lua_State *mp_state;
};