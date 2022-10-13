#!/bin/zsh
clang++ -O2 -shared -DNET5_0 -Iinclude clr.cpp -std=c++17 -o libclr.dylib
clang++ -O2 -shared -std=c++17 -o libjs.dylib -I${V8_INCLUDE}/include js.cpp -L${V8_LIB} -lv8_monolith -pthread -std=c++14 -DV8_COMPRESS_POINTERS
gcc  -O2 -o bin/driveIn -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/darwin -I${PYTHON_INCLUDE} driveInRuntime.c py.c -L${PYTHON_LIB} -lpython3.9 -L${JAVA_HOME}/lib/ -L${JAVA_HOME}/lib/server/ -ljli -ljvm -L. -ljs -lclr
gcc  -O2 -o bin/driveInConfBenchmark -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/darwin -I${PYTHON_INCLUDE} driveInRuntimeBenchmark.c py.c -L${PYTHON_LIB} -lpython3.9 -L${JAVA_HOME}/lib/ -L${JAVA_HOME}/lib/server/ -ljli -ljvm -L. -ljs -lclr