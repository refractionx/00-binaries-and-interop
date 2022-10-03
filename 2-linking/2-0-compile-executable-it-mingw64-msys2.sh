#!/bin/bash
gcc -O0 -I../1-libraries/include -L../1-libraries/lib64/win64 -lgreetings-it-mingw64-msys2 -o bin/win64/helloWorld-it-mingw64-msys2.exe helloWorld.c 