#!/bin/zsh
export WASI_SDK_ROOT=wasi-sdk-16.0
export WASI_SYSROOT=wasi-sdk-16.0/share/wasi-sysroot/

${WASI_SDK_ROOT}/bin/clang -O2 -Wl,--no-entry -mexec-model=reactor --sysroot ${WASI_SYSROOT} static/webassembly/greetings-bg.o -o lib/webassembly/greetings-bg.wasm
${WASI_SDK_ROOT}/bin/clang -O2 -Wl,--no-entry -mexec-model=reactor --sysroot ${WASI_SYSROOT} static/webassembly/greetings-it.o -o lib/webassembly/greetings-it.wasm
