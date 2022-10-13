#include <greetings.h>

static char *helloWorld = "Ciao mondo!";

API __attribute__((export_name("getGreetingMessage")))
char *getGreetingMessage() {
    return helloWorld;
}

API
char *getExitMessage() {
    return "";
}

API
char buffer[100] = "A";
