#!/bin/bash
gcc -fPIC -flto -shared -O2 -Iinclude -o lib64/linux64/libgreetings-bg.so greetings-bg.c 