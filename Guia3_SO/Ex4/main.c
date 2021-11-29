#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[])
{
    argv[0]="123";
    execv("./ex3",argv);

    printf("Hello world!\n");
    return 0;
}
