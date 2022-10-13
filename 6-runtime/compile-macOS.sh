#!/bin/zsh
clang++ -O2 -shared -DNET5_0 -Iinclude clr.cpp -std=c++17 -o libclr.dylib
clang++ -O2 -shared -std=c++17 -o libjs.dylib -I/Users/samuil_aleksov/dev/tmp/v8/include js.cpp -L/Users/samuil_aleksov/dev/tmp/v8/out.gn/x64.release.sample/obj/ -lv8_monolith -pthread -std=c++14 -DV8_COMPRESS_POINTERS
/usr/local/Cellar/gcc/12.2.0/bin/gcc-12  -O2 -o bin/driveIn -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/darwin -I/usr/local/opt/python@3.9/Frameworks/Python.framework/Versions/3.9/include/python3.9 driveInRuntime.c py.c -L/usr/local/opt/python@3.9/Frameworks/Python.framework/Versions/3.9/lib -lpython3.9 -L${JAVA_HOME}/lib/ -L${JAVA_HOME}/lib/server/ -ljli -ljvm -L. -ljs -lclr
/usr/local/Cellar/gcc/12.2.0/bin/gcc-12  -O2 -o bin/driveInConfBenchmark -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/darwin -I/usr/local/opt/python@3.9/Frameworks/Python.framework/Versions/3.9/include/python3.9 driveInRuntimeBenchmark.c py.c -L/usr/local/opt/python@3.9/Frameworks/Python.framework/Versions/3.9/lib -lpython3.9 -L${JAVA_HOME}/lib/ -L${JAVA_HOME}/lib/server/ -ljli -ljvm -L. -ljs -lclr