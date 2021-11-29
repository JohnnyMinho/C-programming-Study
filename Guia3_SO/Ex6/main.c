#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int status;
    if(fork() == 0){
        execlp(argv[1],argv[1],argv+2,NULL);
    }
    else{
        wait(&status);
        if(WIFEXITED(status)){
            int saida = WEXITSTATUS((status));
            return saida;
        }
        else{
            return -1;
        }
    }
}
