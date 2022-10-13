#!/bin/bash
gcc -O0 -I../1-libraries/include -o bin/linux64/helloWorld-bg helloWorld.c -L../1-libraries/lib64/linux64 -lgreetings-bg