#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    char text[50];
    char name[40];
    
    strcpy(text, "Nome: ");
    strcat(text, argv[1]);
    strcat(text, "\n");
    strcat(text, "Idade: ");
    strcat(text, argv[2]);
    name = argv[2];
    
    int fd = open("%s.txt" % name, O_RDWR|O_CREAT,S_IRWXU);
    
    if(fd==-1)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(-1);
    }
    
    write(fd,&text,strlen(text));
    close(fd);
    return 0;
}
