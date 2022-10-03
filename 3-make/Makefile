CC = cc
CFLAGS = -I../1-libraries/include -O0
LDFLAGS = -L../1-libraries/static/macOS -lgreetings-it
OUTPUT = bin/macOS/helloWorld

ifeq ($(OS), Windows_NT)
		CC = clang
		LDFLAGS = -Xlinker /subsystem:console
		OUTPUT = bin/win64/helloWorld.exe
else
	UNAME := $(shell uname)
	ifneq (, $(findstring MINGW64_NT,$(UNAME)))
		LDFLAGS = -L../1-libraries/static/win64 -lgreetings-it-mingw64-msys2
		OUTPUT = bin/win64/helloWorld-mingw64-msys2.exe
	endif
endif

.PHONY = all clean

all: helloWorld

helloWorld: helloWorld.o
	${CC} helloWorld.o ${LDFLAGS} -o ${OUTPUT}

helloWorld.o:
	${CC} ${CFLAGS} -c ../2-linking/helloWorld.c

clean:
	rm -rvf helloWorld.o $(OUTPUT)