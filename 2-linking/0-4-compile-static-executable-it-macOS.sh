#!/bin/zsh
clang -O0 -I../1-libraries/include -L../1-libraries/static/macOS/ -lgreetings-it -o bin/macOS/helloWorld-it-static helloWorld.c