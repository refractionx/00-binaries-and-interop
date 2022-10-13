#!/bin/zsh
clang -dynamiclib -O0 -Iinclude -o lib64/macOS/libgreetings-it.dylib greetings-it.c 