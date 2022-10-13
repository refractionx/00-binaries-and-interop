# Demo code for the Drive-In Conf's Back2Basics: Binaries and Interoperability talk

## This is a beginner's guide to binary executables, libraries and cross-platform interoperability

- Includes examples of dynamic and static linking w/o optimizations done by different compilers

- Examples of different build systems and runtimes (GCC/CLANG/MINGW/MSVC)

- Example code for interoperability from Java, C#, JavaScript, Python and WebAssembly to C

- Example code for C/C++ runtime to Java, C#, JavaScript and Python

### Left to the user

Play with different environment variables:
 - DYLD_LIBRARY_PATH (macOS), LD_LIBRARY_PATH (linux), PATH (Windows)
 - JAVA_HOME check to see what happends on different versions
 - PYTHON_INCLUDE PYTHON_LIB check what happens if you mix python versions

### Port our runtime

The drive in runtime only works on my machine
 - Build V8 and set the right V8_INCLUDE and V8_LIB variables
 - Identify the right path for hostfxr on your machine
 - Write a compilation script that works for your OS 

A research by Sam Aleksov / [refractionx.com](https://refractionx.com).
