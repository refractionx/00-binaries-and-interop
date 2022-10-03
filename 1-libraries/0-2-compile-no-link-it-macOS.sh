clang -O2 -flto -Iinclude -c greetings-it.c -fPIC
ar r static/libgreetings-it.a greetings-it.o