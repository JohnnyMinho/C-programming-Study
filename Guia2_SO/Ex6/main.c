#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */
#include <string.h>

int Search_Line(int n, int L, int C, int matrix[L][C], int nLinha);

int main(int argc, char *argv[])
{
    int n,C,L,i,j;

    if(argc == 4){
        C = atoi(argv[1]);
        L = atoi(argv[2]);
        n = atoi(argv[3]);
    }
    else{
        printf("WRONG NUMBER OF ARGUMENTS");
    }
    int FoundLine[L];
    int contador = 0;
    /*FORM MATRIX*/
    int Matriz[L][C];
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            Matriz[i][j] = rand()%10;
            printf("%d ",Matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    //START MAKING KIDS
    int y=0;
    int status;
    for(i = 0; i<L; i++){
        if(fork() == 0){
            y = Search_Line(n,L,C,Matriz,i);
            if(y != 0){
                contador++;
                for(j=0;j<C;j++){
                    FoundLine[contador] = i;
                    printf("%d ", Matriz[i][j]);
                }
                printf("\n");
                if(contador != 0){
                    int array_ordenado[contador];
                    printf("Found on line : %d \n", FoundLine[contador]+1);
                }
            }
            _exit(y);
        }
    }

    int result = 0;
    for(i = 0;i<L; i++){
        wait(&status);
        if(WIFEXITED(status)){ //If the child process for which status was returned by the wait or waitpid function exited normally, the WIFEXITED macro evaluates to TRUE and the WEXITSTATUS macro is used to query the exit code of the child process. Otherwise, the WIFEXITED macro evaluates to FALSE.
            result += WEXITSTATUS(status);
        }
        if(result > 0){
            printf("The number: %d , was found %d times\n", n,result);
        }
        else{
            printf("No results were found\n");
        }
    }
    return 0;
}

int Search_Line(int n, int L, int C, int matrix[L][C], int nLinha){
    int i = 0;
    int j = 0;
    for(i = 0; i < C; i++){
        if(matrix[nLinha][i] == n){
            j++;
        }
    }
    return j;
}
