cmake_minimum_required(VERSION 3.10.0)
project(lua-demo VERSION 0.1.0 LANGUAGES C)

add_executable(
    lua-demo
    main.c
    lua/lapi.c
    lua/lauxlib.c
    lua/lcode.c
    lua/ltable.c
    lua/lgc.c
    lua/lstate.c
    lua/ldo.c
    lua/lmem.c
    lua/lfunc.c
    lua/ldebug.c
    lua/lparser.c
    lua/lundump.c
    lua/lobject.c
    lua/lctype.c
    lua/lvm.c
    lua/ltm.c
    lua/lstring.c
    lua/lzio.c
    lua/llex.c
    lua/lopcodes.c
    lua/linit.c
    lua/ldblib.c
    lua/lutf8lib.c
    lua/lmathlib.c
    lua/lstrlib.c
    lua/loslib.c
    lua/liolib.c
    lua/ltablib.c
    lua/lcorolib.c
    lua/loadlib.c
    lua/lbaselib.c
    lua/ldump.c
)


if(UNIX AND NOT APPLE)
    target_link_libraries(lua-demo PRIVATE m)
endif()