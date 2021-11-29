#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char buffer[1024];
    int f1,f2,f3,i;

    f1 = open("/etc/passwd", O_RDONLY);
    f2 = open("saidas.txt", O_CREAT |O_TRUNC| O_WRONLY , 0666);
    f3 = open("erros.txt", O_CREAT |O_TRUNC| O_WRONLY , 0666);

    /* com dup
    close(0);
    dup(f1);
    close(f1);
    close(1);
    dup(f2);
    close(f2);
    close(2)
    dup(f3);
    close(f3)

    */
    dup2(f1,0);
    close(f1);
    dup2(f2,1);
    close(f2);
    dup2(f3,2);
    close(f3);

    while((i =read(0,buffer,sizeof(buffer)))>0){
        write(1,buffer,i);
    }
    return 0;

}
