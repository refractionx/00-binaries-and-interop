#include <stdio.h>

static char *helloWorld = "Hello world!";

char *getGreetingMessage() {
    return helloWorld;
}

int main(int argc, char **argv, char **env) {
    printf("%s", getGreetingMessage());
    return 0;
}

char data[100] = "A";