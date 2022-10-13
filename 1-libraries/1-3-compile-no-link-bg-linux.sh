#!/bin/bash
gcc -O2 -flto -fPIC -Iinclude -c greetings-bg.c -o greetings-bg.o
ar rcs static/linux64/libgreetings-bg.a greetings-bg.o