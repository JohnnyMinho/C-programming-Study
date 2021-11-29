#include <stdio.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */
#include <string.h>

int main(int argc, char *argv[])
{
    int i = 0;
    int status;
    for(i=0;i<10;i++){
        if(fork()==0){
            printf("Pai: %d, Filho: %d \n", getppid(), getpid());
        }
        else{
        wait(&status);
        printf("I don't feel so good: %d", getpid());
        _exit(0);
        }
    }

    return 0;
}
