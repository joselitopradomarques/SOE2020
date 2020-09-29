#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1000

int main(int argc, const char *argv[])
{
    FILE *fp;
    int count;
    
    fp = fopen (argv[2], "r+");
    
    count = counter(fp, argv[1]);
    printf("'%s' ocorre %d vezes no arquivo '%s'", argv[1], count, argv[2]);
    
    fclose(fp);

    return 0;
}

int counter(FILE *fp, const char *word)
{
    char str[BUFFER];
    char *pos;

    int index, count;
    
    count = 0;

    while ((fgets(str, BUFFER, fp)) != NULL)
    {
        index = 0;

        while ((pos = strstr(str + index, word)) != NULL)
        {
            // Index of word in str is
            // Memory address of pos - memory
            // address of str.
            index = (pos - str) + 1;

            count++;
        }
    }

    return count;
}

