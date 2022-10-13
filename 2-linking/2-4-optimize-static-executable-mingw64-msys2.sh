#!/bin/bash
gcc -flto -O2 -I../1-libraries/include -o bin/win64/helloWorld-bg-mingw64-msys2-optimized-static.exe helloWorld.c -L../1-libraries/static/win64/ -lgreetings-bg-mingw64-msys2