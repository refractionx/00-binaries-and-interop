#!/bin/zsh
PYTHONUNBUFFERED=1 PYTHONPATH="$(pwd)" DYLD_LIBRARY_PATH="${JAVA_HOME}/lib/:${JAVA_HOME}/lib/server/" bin/driveInConfBenchmark plugins.driveInPlugin
