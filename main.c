#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <memory.h>
#include "lua/lauxlib.h"
#include "lua/lualib.h"

int luaopen_mylib(lua_State *L);

int main(int argn, char **argv)
{
    printf("hello\n");
    struct timespec spec;
    clock_gettime(0, &spec);
    printf("%d, %d\n", spec.tv_sec, spec.tv_nsec);
    printf("%p\n", gettimeofday);

    lua_State *L = luaL_newstate();
    luaL_openlibs(L);
    luaL_requiref(L, "mylib", luaopen_mylib, 1);
    lua_pop(L, 1);

    if (argn < 2)
    {
        const char *test = "local mylib = require 'mylib';print(mylib.add(100,200))";
        luaL_dostring(L, test);
        return 0;
    }

    const char *file = argv[1];
    printf("dofile %s\n", file);
    int result = luaL_dofile(L, file);
    if (result != LUA_OK)
    {
        fprintf(stderr, "do file error:%s\n", lua_tostring(L, -1));
        lua_pop(L, 1);
        lua_close(L);
    }
}

int mylib_add(lua_State *L)
{
    double a = lua_tonumber(L, -1);
    double b = lua_tonumber(L, -2);
    lua_pushnumber(L, a + b);
    return 1;
}

int luaopen_mylib(lua_State *L)
{
    luaL_Reg funcs[] = {
        {"add", mylib_add},
        {NULL, NULL},
    };
    luaL_newlib(L, funcs);
    return 1;
}