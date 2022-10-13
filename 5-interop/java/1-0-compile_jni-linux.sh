#!/bin/bash
export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64
gcc -fPIC -I../../1-libraries/include -I${JAVA_HOME}/include -I${JAVA_HOME}/include/linux -o libgreetings-jni.so -shared Program.c -Llib64/linux64 -lgreetings-bg