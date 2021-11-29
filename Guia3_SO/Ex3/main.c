#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int i = 0;
    for(i=0;i<argc; i++){
        printf("Arguento n %d : %s", i, argv[i]);
    }
    return 0;
}
