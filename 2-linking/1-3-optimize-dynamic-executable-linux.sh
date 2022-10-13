#!/bin/bash
gcc -O3 -flto -I../1-libraries/include -o bin/linux64/helloWorld-bg-optimized helloWorld.c -L../1-libraries/lib64/linux64/ -lgreetings-bg