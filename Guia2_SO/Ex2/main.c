#include <stdio.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */


int main(int argc, char *argv[])
{
    pid_t pid;
    if((pid=fork() == 0)){
        printf("Father: %d\n", getppid());
        printf("Identificador processo filho: %d \n", getpid());
        wait(NULL);
        _exit(0);
    }
    else{
        printf("Bash: %d\n", getppid());
        printf("Identificador processo pai: %d \n", getpid());
        printf("Identificador processo filho: %d\n", pid);
    }
    return 0;
}
