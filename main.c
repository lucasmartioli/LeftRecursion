//
// Created by Lucas on 11/10/2016.
//

#include <stdio.h>
#include "readgramar.h"
//#include <conio.h>

int main(int argc, char *argv[])
{
    printf("Quantidade de parametros de entrada: %d\n", argc);
    if (argc != 2)
    {
       printf("Deve ser passado o nome do arquivo de entrada como parametro de execucao. Apenas o nome do arquivo de entrada.\n");
       return 0;
    }

    GramaticalRule* s = readgramar(argv[1]);
    if (!s)
    {
        printf("Problemas na leitura da gramatica. Verifique o formato de entrada!");
        return 0;
    }

    GramaticalRule* atual = s;
    while (atual != NULL)
    {
        printf("Key: %c Regra: %s \n", atual->key, atual->rule);
        atual = atual->next;
    }

    return 1;
}

