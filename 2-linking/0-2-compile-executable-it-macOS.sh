#!/bin/zsh
clang -O0 -I../1-libraries/include -L../1-libraries/lib64/macOS -lgreetings-it -o bin/macOS/helloWorld-it helloWorld.c 