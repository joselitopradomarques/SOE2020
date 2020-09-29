#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char name[100];
    char age[2];
    char ask1[] = "Digite o seu nome: ";
    char ask2[] = "Digite a sua idade: ";
    
    printf("%s", ask1);
    scanf("%s", name);
    printf("%s", ask2);
    scanf("%s", age);
    
    int fd = open("name.txt", O_RDWR|O_CREAT,S_IRWXU);
    
    int i = 0;
    
    if(fd==-1)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(-1);
    }
    
    strcpy(name, "Digite o seu nome: ");
    strcpy(age, "Digite a sua idade: ");
    
    write(fd,&name,strlen(name));
#for (i=0; name[i]!=0; i++)
#    write(fd,&(name), 1);
#for (i=0; age[i]!=0; i++)
#    write(fd,&(age), 1);

    close(fd);
    return 0;
}
