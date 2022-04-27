cmake_minimum_required(VERSION 3.22)
project(win_flex_bison_latest)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(data)

add_executable(win_flex_bison_latest
        data/glr.c
        data/glr.cc
        data/lalr1.cc
        data/location.cc
        data/stack.hh
        data/yacc.c
        FlexLexer.h
        lex.yy.c)
