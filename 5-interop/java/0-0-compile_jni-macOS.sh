#!/bin/zsh
gcc -fPIC -I../../1-libraries/include -I${JAVA_HOME}/include -I${JAVA_HOME}/include/darwin -o libgreetings-jni.dylib -shared Program.c -Llib64/macOS -lgreetings-bg