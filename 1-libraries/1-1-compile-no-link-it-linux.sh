#!/bin/bash
gcc -O2 -flto -fPIC -Iinclude -c greetings-it.c -o greetings-it.o
ar rcs static/linux64/libgreetings-it.a greetings-it.o