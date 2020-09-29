#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, const char *argv[])
{
    char file[50];
    char word[50];
    char command[200];
    
    strcpy(word, argv[1]);
    strcpy(file, argv[2]);
    strcpy(command, "grep -o -i ");
    strcat(command, word);
    strcat(command, " ");
    strcat(command, file);
    strcat(command, " | wc -l ");
    
/*
    int fd = open(file, O_RDWR|O_CREAT,S_IRWXU);

    
    if(fd==-1)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(-1);
    }
*/
    printf("'%s' ocorre ", word);
    system(command);
    printf("vezes no arquivo %s", file);
 
    return 0;
}
