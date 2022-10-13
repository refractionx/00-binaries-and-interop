#!/bin/bash
gcc -O0 -I../1-libraries/include -o bin/linux64/helloWorld-it-static helloWorld.c -L../1-libraries/static/linux64/ -lgreetings-it