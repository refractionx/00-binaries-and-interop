cl /O2 /GL /c /EHsc -Iinclude greetings-bg.c  /Fogreetings-bg.obj
lib greetings-bg.obj /OUT:static\\win64\\libgreetings-bg.lib