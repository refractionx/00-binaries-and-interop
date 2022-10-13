#pragma once

#if _MSC_VER & _DLLEXPORT
#define API __declspec(dllexport)
#elif _MSC_VER & _DLLIMPORT
#define API __declspec(dllimport) 
#else
#define API
#endif

API
char *getGreetingMessage();

API
char *getExitMessage();