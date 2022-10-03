#!/bin/bash
gcc -O0 -I../1-libraries/include -o bin/win64/helloWorld-it-mingw64-msys2-static.exe helloWorld.c -L../1-libraries/static/win64/ -lgreetings-it-mingw64-msys2