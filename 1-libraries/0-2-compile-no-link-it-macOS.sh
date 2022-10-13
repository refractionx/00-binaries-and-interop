#!/bin/zsh
clang -O2 -flto -Iinclude -c greetings-it.c -fPIC
ar r static/macOS/libgreetings-it.a greetings-it.o