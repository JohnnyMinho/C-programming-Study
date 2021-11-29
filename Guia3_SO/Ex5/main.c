#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int i,status;
    for(i=0;i<argc;i++){
        if(!fork()){
            execlp(argv[i],argv[i],NULL);
            _exit(-1);
        }
    }
    for(i=0;i<argc;i++){
        wait(&status);
    }
    printf("I'm shutting off");
    return 0;
}
