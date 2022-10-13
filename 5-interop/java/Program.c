#include "Program.h"
#include <greetings.h>

JNIEXPORT jstring JNICALL Java_Program_getGreetingMessageNative
  (JNIEnv *env, jobject javaThis) {
    return (*env)->NewStringUTF(env, getGreetingMessage());
}