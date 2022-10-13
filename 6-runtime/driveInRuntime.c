#include <unistd.h>

#include "jvm.h"
#include "py.h"
#include "js.h"
#include "clr.h"

int main(int argc, char **argv)
{   
    loadJVM();
    loadPython(argc, argv);
    loadJS(argc, argv);
    loadCLR(argc, argv);

    long ticks = 0;
    char data[32];
    
    
    while(1) {
        sprintf(data, "%ld", ticks++);
        printf("------------------------\n");
        printf(" ");        fflush(stdout);

        tickJVM(data);      printf("\n");

        tickPython(data);   printf("\n");
        
        tickJS(data);       printf("\n");
        
        tickCLR(data);      printf("\n");
        
        sleep(1);
    }
    
	return 0;
}
