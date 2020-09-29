//
//  ola_argumentos.c
//  
//
//  Created by Joselito Prado on 02/09/20.
//

#include "ola_argumentos.h"
#include <stdio.h>
#include <stdlib.h>

int i;
int main(int argc, char **argv)
{
    printf("Argumentos: ");
    for (i = 1; i<argc; i++) {
        printf("%s ", argv[i]);
    }
    return 0;
}

