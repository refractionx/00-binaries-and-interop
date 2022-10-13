#pragma once

#include <jni.h>

static int 			   res;
static jclass          cls;
static jmethodID       mid;
static jstring		   jstr;
static JavaVM          *vm;
static JNIEnv          *env;

int loadJVM() {
    JavaVMInitArgs  vm_args;
    JavaVMOption options[2];
    options[0].optionString    = "-Djava.class.path=plugins/";
    options[1].optionString    = "-Xmx10M"; 
    vm_args.options            = options;
    vm_args.nOptions           = 2;
    vm_args.ignoreUnrecognized = JNI_FALSE;
	vm_args.version  = JNI_VERSION_1_8;
	

	res = JNI_CreateJavaVM(&vm, (void **)&env, &vm_args);
	if (res != JNI_OK) {
		printf("Failed to create Java VMn");
		return 1;
	}

	cls = (*env)->FindClass(env, "DriveInPlugin");
	if (cls == NULL) {
		printf("Failed to find Main classn");
		return 1;
	}

	mid = (*env)->GetStaticMethodID(env, cls, "tick", "(Ljava/lang/String;)V");
	if (mid == NULL) {
		printf("Failed to find main functionn");
		return 1;
	}
}

void tickJVM(char *data) {
	jstr = (*env)->NewStringUTF(env, data);
	(*env)->CallStaticVoidMethod(env, cls, mid, jstr);
	(*env)->DeleteLocalRef(env, jstr);
}