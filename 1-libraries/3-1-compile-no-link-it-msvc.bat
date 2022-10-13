cl /O2 /GL /c /EHsc -Iinclude greetings-it.c  /Fogreetings-it.obj
lib greetings-it.obj /OUT:static\\win64\\libgreetings-it.lib