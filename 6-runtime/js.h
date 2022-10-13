#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void tickJS(char *data);

void tickCPP(char *data);

int loadJS(int argc, char* argv[]);

#ifdef __cplusplus
}
#endif