clang -O2 -flto -Iinclude -c greetings-bg.c -fPIC
ar r static/libgreetings-bg.a greetings-bg.o