#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void tickCLR(char *data);

#if defined(WINDOWS)
int __cdecl loadCLR(int argc, wchar_t *argv[]);
#else
int loadCLR(int argc, char *argv[]);
#endif

#ifdef __cplusplus
}
#endif