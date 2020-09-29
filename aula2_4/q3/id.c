#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    FILE * fp;
    int i;
    char name[50], text[55], age[5];
    
    fp = fopen ("ola_usuario_2.txt", "w+");
    strcpy(text, "Nome: ");
    strcat(text, argv[1]);
    strcat(text, "\n");
    strcat(text, "Idade: ");
    strcat(text, argv[2]);

    
    for(i=0;text[i]!='\0';i++)
        putc(text[i], fp);
    //fwrite(text , 1 , sizeof(text) , fp );
    putc('\n',fp);
    fclose(fp);

    return 0;
}

