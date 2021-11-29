#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = 0;
    if((pid = fork())==0){
        printf("Father: %d, Son: %d", getpid(),getppid());
        execlp("ls","ls","-l",NULL);
        printf("If i'm printed, something went wrong");
    }
    return 0;
}
