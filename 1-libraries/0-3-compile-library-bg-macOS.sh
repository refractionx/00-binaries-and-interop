#!/bin/zsh
clang -dynamiclib -O0 -Iinclude -o lib64/macOS/libgreetings-bg.dylib greetings-bg.c 