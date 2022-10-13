#include <time.h>
#include <unistd.h>

#include "jvm.h"
#include "py.h"
#include "js.h"
#include "clr.h"

#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct timespec timespec;
static inline void diff(timespec *start, timespec *end, timespec *result);

int main(int argc, char **argv)
{
    timespec start, end;
    timespec totalJ;
    timespec totalCLR;
    timespec totalJS;
    timespec totalPy;
    timespec totalC;
    timespec totalCPP;
    unsigned long maxJ = 0;
    unsigned long maxCLR = 0;
    unsigned long maxJS = 0;
    unsigned long maxPy = 0;
    unsigned long maxC = 0;
    unsigned long maxCPP = 0;
    
    clock_gettime(CLOCK_REALTIME, &start);
    loadJVM();
    clock_gettime(CLOCK_REALTIME, &end);
    timespec total;
    diff(&start, &end, &total);
    printf("Loading JVM %lu ms.\n", total.tv_nsec / 1000000L);

    clock_gettime(CLOCK_REALTIME, &start);
    loadPython(argc, argv);
    clock_gettime(CLOCK_REALTIME, &end);
    diff(&start, &end, &total);
    printf("Loading Python %lu ms.\n", total.tv_nsec / 1000000L);

    clock_gettime(CLOCK_REALTIME, &start);
    loadJS(argc, argv);
    clock_gettime(CLOCK_REALTIME, &end);
    diff(&start, &end, &total);
    printf("Loading JS %lu ms.\n", total.tv_nsec / 1000000L);

    clock_gettime(CLOCK_REALTIME, &start);
    loadCLR(argc, argv);
    clock_gettime(CLOCK_REALTIME, &end);
    diff(&start, &end, &total);
    printf("Loading CLR %lu ms.\n", total.tv_nsec / 1000000L);

    long ticks = 0;
    char data[32];
    int epoch = 0;

    timespec mainLoopStart;
    clock_gettime(CLOCK_REALTIME, &mainLoopStart);

    printf("EPOCH |");
    printf(" JAVA OUT  |");
    printf(" PYTHON OUT |");
    printf("   JS OUT   |");
    printf("   .NET OUT |");
    printf("   C OUT   |");
    printf("   C++ OUT   |");
    printf("  JVM curr ns. /worst μs. |");
    printf(" V8  curr ns. /worst μs. |");
    printf(" Py  curr ns. /worst μs. |");
    printf("  CLR curr ns. /worst μs. |");
    printf("  C curr ns. /worst μs. |");
    printf("  C++ curr ns. /worst μs. |");
    
    printf("\n");

    while(1) {

        sprintf(data, "%ld", ticks++);
        printf("%4d: | ", epoch);
        fflush(stdout);

        clock_gettime(CLOCK_REALTIME, &start);
        tickJVM(data);
        clock_gettime(CLOCK_REALTIME, &end);
        diff(&start, &end, &totalJ);
        maxJ = MAX(totalJ.tv_nsec, maxJ);
        printf(" | ");
        fflush(stdout);

        clock_gettime(CLOCK_REALTIME, &start);
        tickPython(data);
        clock_gettime(CLOCK_REALTIME, &end);
        diff(&start, &end, &totalPy);
        maxPy = MAX(totalPy.tv_nsec, maxPy);
        printf(" | ");
        fflush(stdout);

        clock_gettime(CLOCK_REALTIME, &start);
        tickJS(data);
        clock_gettime(CLOCK_REALTIME, &end);
        diff(&start, &end, &totalJS);
        maxJS = MAX(totalJS.tv_nsec, maxJS);
        printf(" | ");
        fflush(stdout);

        clock_gettime(CLOCK_REALTIME, &start);
        tickCLR(data);
        clock_gettime(CLOCK_REALTIME, &end);
        diff(&start, &end, &totalCLR);
        maxCLR = MAX(totalCLR.tv_nsec, maxCLR);
        printf(" | ");
        fflush(stdout);

        clock_gettime(CLOCK_REALTIME, &start);
        tickC(data);
        clock_gettime(CLOCK_REALTIME, &end);
        diff(&start, &end, &totalC);
        maxC = MAX(totalC.tv_nsec, maxC);
        printf(" | ");
        fflush(stdout);

        clock_gettime(CLOCK_REALTIME, &start);
        tickCPP(data);
        clock_gettime(CLOCK_REALTIME, &end);
        diff(&start, &end, &totalCPP);
        maxCPP = MAX(totalCPP.tv_nsec, maxCPP);

        printf(" | ");
        printf("jvm: % 5lu ns./% 5lu μs.", totalJ.tv_nsec, maxJ / 1000L);

        printf(" | ");
        printf("js: % 5lu ns./% 5lu μs.", totalJS.tv_nsec, maxJS / 1000L);

        printf(" | ");
        printf("py: % 5lu ns./% 5lu μs.", totalPy.tv_nsec, maxPy / 1000L);

        printf(" | ");
        printf("clr: % 5lu ns./% 5lu μs.", totalCLR.tv_nsec, maxCLR / 1000L);

        printf(" | ");
        printf("c: % 5lu ns./% 5lu μs.", totalC.tv_nsec, maxC / 1000L);

        printf(" | ");
        printf("c++: % 5lu ns./% 5lu μs.", totalCPP.tv_nsec, maxCPP / 1000L);

        printf("\r");

        timespec loopEnd;
        timespec epochTime;
        clock_gettime(CLOCK_REALTIME, &loopEnd);
        diff(&mainLoopStart, &loopEnd, &epochTime);
        if (epochTime.tv_sec > 3) {
            printf("\n");
            maxJS = 0;
            maxCLR = 0;
            maxPy = 0;
            maxC = 0;
            maxCPP = 0;
            maxJ = 0;
            ticks = 0;
            mainLoopStart = loopEnd;
            epoch++;
        }
    }
    
	return 0;
}


static inline void diff(timespec *start, timespec *end, timespec *result) {
    result->tv_sec  = end->tv_sec  - start->tv_sec;
    result->tv_nsec = end->tv_nsec - start->tv_nsec;
    if (result->tv_nsec < 0) {
        --result->tv_sec;
        result->tv_nsec += 1000000000L;
    }
}