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
        if((pid=fork())== 0){
            sprintf(string, "Pai: %d Filho: %d Status Saida: %d \n", getppid(), getpid(),getpid()-getppid());
            write(1,string,strlen(string));
            _exit(i+1);
        }
        sprintf(string, "Bash: %d Pai: %d\n", getppid(), getpid());
        write(1,string,strlen(string));
        pid = wait(&status); //guarda o valor do filho que morreu no pid / retorna o indicidor do filho que morreu
        if(WIFEXITED(status)){ //Verifica se o filho morreu de maneira normal
            sprintf(string,"%d %d \n",pid,WEXITSTATUS(status)); //WEXTISTATUS dá o valor de saída do filho quando este morre normalmente sendo que quando o mesmo não acontece, o valor devolvido não tem sentido.
            write(1,string,strlen(string)); //verificação basicamente
        }
    }
    return 0;
}
