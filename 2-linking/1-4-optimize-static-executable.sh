#!/bin/bash
gcc -flto -O2 -I../1-libraries/include -o bin/linux64/helloWorld-bg-optimized-static helloWorld.c -L../1-libraries/static/linux64/ -lgreetings-bg