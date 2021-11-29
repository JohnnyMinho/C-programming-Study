#include <stdio.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */

int main(int argc, char *argv[])
{

    pid_t idparent= getppid();
    pid_t id = getpid();
    printf("%d \n", idparent);
    printf("%d ", id);
  /*  pid_t pid;
    int status;
    int status_dad;
    if((pid == 0)){ // Retorna da chamada do pai;
        status = getpid();
        printf("Identificador processo filho: %d \n", status);
        wait(NULL);
        _exit(0);
    }
    if(pid>1){ //Verifica se foi criado um filho
        status_dad = getppid();
        status = getpid();
        printf("Identificador processo pai: %d \n", status_dad);
        printf("Identificador processo filho: %d", status);
    }
    if(pid == -1){ //Não houve criação de filhos
        printf("Sem filhos");
    } */
    return 0;
}
