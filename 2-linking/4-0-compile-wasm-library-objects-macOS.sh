#!/bin/zsh
export WASI_SDK_ROOT=wasi-sdk-16.0
export WASI_SYSROOT=wasi-sdk-16.0/share/wasi-sysroot

${WASI_SDK_ROOT}/bin/clang -c -O2 --sysroot ${WASI_SYSROOT} -I../1-libraries/include ../1-libraries/greetings-bg.c  -o static/webassembly/greetings-bg.o
${WASI_SDK_ROOT}/bin/clang -c -O2 --sysroot ${WASI_SYSROOT} -I../1-libraries/include ../1-libraries/greetings-it.c -o static/webassembly/greetings-it.o
