#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE * fp;
    int i;
    char name[50], text[500], age[5];
    
    // abertura do arquivo
    fp = fopen ("ola_mundo_putc.txt", "w+");
    
    // "Digite o seu nome" e escreva "Nome: - " no texto
    printf("Digite o seu nome: ");
    scanf("%s", name);
    strcpy(text, "Nome: ");
    strcat(text, name);
    strcat(text, "\n");
    
    // "Digite a sua idade" e escreva "Idade: - " no texto
    printf("Digite sua idade: ");
    scanf("%s", age);
    strcat(text, "Idade: ");
    strcat(text, age);
    strcat(text, " anos");
    
    // escrita da string final no arquivo
    //for(i=0;text[i]!='\0';i++)
    //    putc(text[i], fp);
    fwrite(text , 1 , sizeof(text) , fp );
    putc('\n',fp);
    fclose(fp);

    return 0;
}

