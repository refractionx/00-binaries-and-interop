## Changes
 - 8MB of garbage data for the optimization demos has been reduced to 100 bytes, so that we keep the final result (binaries) in VC, this is both executables and libraries.
 You can set it back to more impactful sizes by changing e.g.: 
   - `char data[100] = "A";` to e.g. `char data[1920*1080*4] = "A";`
   - `char buffer[100] = "A";` to e.g. `char buffer[1920*1080*4] = "A";`

## For WebAssembly & WASI

Set WASI_SDK_ROOT and WASI_SYSROOT to the location where you downloaded them on your workstation.

Use wasmtime or wagi to test