#!/bin/bash
gcc -O2 -flto -fPIC -Iinclude -c greetings-bg.c -o greetings-bg-mingw64-msys2.o
ar rcs static/win64/libgreetings-bg-mingw64-msys2.a greetings-bg-mingw64-msys2.o