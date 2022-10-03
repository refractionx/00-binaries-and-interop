CC = clang
CFLAGS = -I../1-libraries/include -O2 -flto
LDFLAGS = -L../1-libraries/static -lgreetings-it

.PHONY = all clean

all: helloWorld

helloWorld: helloWorld.o
	${CC} ${LDFLAGS} helloWorld.o -o helloWorld

helloWorld.o:
	${CC} ${CFLAGS} -c ../2-linking/helloWorld.c

clean:
	rm -rvf helloWorld.o helloWorld