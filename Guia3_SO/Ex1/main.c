#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    execlp("ls","ls","-l",NULL);
    printf("If i'm printed, something went wrong");
    return 0;
}
