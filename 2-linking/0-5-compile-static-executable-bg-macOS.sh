#!/bin/zsh
clang -O0 -I../1-libraries/include -L../1-libraries/static/macOS/ -lgreetings-bg -o bin/macOS/helloWorld-bg-static helloWorld.c