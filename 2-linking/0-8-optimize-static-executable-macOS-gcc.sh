#!/bin/zsh
gcc -flto -O2 -I../1-libraries/include -L../1-libraries/static/macOS/ -lgreetings-bg -o bin/macOS/helloWorld-bg-optimized-static-gcc helloWorld.c