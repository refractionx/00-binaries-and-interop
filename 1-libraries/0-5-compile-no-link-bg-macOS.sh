#!/bin/zsh
clang -O2 -flto -Iinclude -c greetings-bg.c -fPIC
ar r static/macOS/libgreetings-bg.a greetings-bg.o