#!/bin/bash
gcc -O2 -flto -fPIC -Iinclude -c greetings-it.c -o greetings-it-mingw64-msys2.o
ar rcs static/win64/libgreetings-it-mingw64-msys2.a greetings-it-mingw64-msys2.o