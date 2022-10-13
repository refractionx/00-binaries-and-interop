#!/bin/zsh
export WASI_SDK_ROOT=wasi-sdk-16.0
export WASI_SYSROOT=wasi-sdk-16.0/share/wasi-sysroot

${WASI_SDK_ROOT}/bin/clang -O2 -flto --sysroot ${WASI_SYSROOT} -I../1-libraries/include helloWorld.c static/webassembly/greetings-bg.o -o bin/webassembly/helloWorld.wasm
