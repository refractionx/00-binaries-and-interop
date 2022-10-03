#!/bin/bash
gcc -fPIC -flto -shared -O2 -Iinclude -o lib64/win64/libgreetings-it-mingw64-msys2.dll greetings-it.c 