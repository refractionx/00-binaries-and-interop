#!/bin/bash
gcc -O3 -flto -I../1-libraries/include -o bin/win64/helloWorld-bg-mingw64-msys2-optimized.exe helloWorld.c -L../1-libraries/lib64/win64/ -lgreetings-bg-mingw64-msys2