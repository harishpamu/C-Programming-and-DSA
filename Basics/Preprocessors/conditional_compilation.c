#include <stdio.h>

#define DEBUG

int main(){
#ifdef DEBUG
   printf("Debug Mode Enabled\n");
#else
    printf("Release Mode\n");
#endif

    return 0;
}