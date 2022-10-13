#!/bin/zsh
clang -O3 -flto -I../1-libraries/include -L../1-libraries/lib64/macOS/ -lgreetings-bg -o bin/macOS/helloWorld-bg-optimized helloWorld.c