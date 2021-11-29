#include <stdio.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */
#include <string.h>


int main(int argc, char *argv[])
{
    pid_t pid;
    int i = 0;
    char string[256];
    int status;
    for(i=0;i<10;i++)
        {
        pid = fork();
        if(pid== 0){
            sprintf(string, "Pai: %d Filho: %d Status Saida: %d \n", getppid(), getpid(),getpid()-getppid());
            write(1,string,strlen(string));
            _exit(i+1);
        }
        sprintf(string, "Father %d EU: %d pid do pid: %d\n", getppid(), getpid(),pid);
        write(1,string,strlen(string));
        }
        for(i=0;i<10;i++){
        pid = wait(&status);
        if(WIFEXITED(status)){
            sprintf(string,"%d %d \n",pid,WEXITSTATUS(status));
        }
    }
    return 0;
}
