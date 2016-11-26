//
// Created by Lucas on 11/10/2016.
//

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "readgrammar.h"
#include "first.h"
#include "follow.h"
#include "table.h"

int writefirstset(FirstSet *firstset);
int writefollowset(FollowSet *followset);

int main(int argc, char *argv[])
{
    printf("Quantidade de parametros de entrada: %d\n", argc);
    if (argc != 2)
    {
       printf("Deve ser passado o nome do arquivo de entrada como parametro de execucao. Apenas o nome do arquivo de entrada.\n");
       return 0;
    }

    GrammarRule* s = readgrammar(argv[1]);
    if (!s)
    {
        printf("Problemas na leitura da gramatica. Verifique o formato de entrada!");
        return 0;
    }

    FirstSet * f = first(s);
    if (!writefirstset(f))
        return 0;

    FollowSet *followset = follow(s, f);
    if (!writefollowset(followset))
        return 0;

    if (!table(s, followset, f))
        return 0;

    return 1;
}

int writefirstset(FirstSet *firstset)
{
    FILE *firstfile = fopen("first.txt", "w");

    if (firstfile == NULL)
    {
        printf("Problemas na criação do arquivo first\n");
        return 0;
    }

    while (firstset != NULL)
    {
        char *desc1 = "Conjunto: ";
        char *notterminal = (char*) malloc(2);
        notterminal[0] = firstset->key;
        notterminal[1] = '\0';
        char *desc2 = " = {";

        if(fwrite(desc1, 1, strlen(desc1), firstfile) != strlen(desc1) ||
           fwrite(notterminal, 1, 1, firstfile)       != 1             ||
           fwrite(desc2, 1, strlen(desc2), firstfile) != strlen(desc2) ||
           fwrite(firstset->set, 1, strlen(firstset->set), firstfile) != strlen(firstset->set) ||
           fwrite("}\n", 1, 2, firstfile) != 2)
        {
            printf("Erro na escrita do arquivo");
            return 0;
        }
        firstset = firstset->next;
    }

    fclose(firstfile);
    return 1;

}
int writefollowset(FollowSet *followset)
{
    FILE *followfile = fopen("follow.txt", "w");

    if (followfile == NULL) {
        printf("Problemas na criação do arquivo follow\n");
        return 0;
    }

    while (followset != NULL) {
        char *desc1 = "Conjunto: ";
        char *notterminal = (char *) malloc(2);
        notterminal[0] = followset->key;
        notterminal[1] = '\0';
        char *desc2 = " = {";

        if (fwrite(desc1, 1, strlen(desc1), followfile) != strlen(desc1) ||
            fwrite(notterminal, 1, 1, followfile) != 1 ||
            fwrite(desc2, 1, strlen(desc2), followfile) != strlen(desc2) ||
            fwrite(followset->set, 1, strlen(followset->set), followfile) != strlen(followset->set) ||
            fwrite("}\n", 1, 2, followfile) != 2) {
            printf("Erro na escrita do arquivo");
            return 0;
        }
        followset = followset->next;
    }

    fclose(followfile);
    return 1;
}

