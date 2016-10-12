//
// Created by Lucas on 10/12/2016.
//

#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include "readgramar.h"

#define TAMANHO_MAXIMO_DA_REGRA 500

GramaticalRule* readgramar(char *filename)
{
    FILE *arquivoDeEntrada = fopen(filename, "rt");

    if (arquivoDeEntrada == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
        return 0;
    }

    GramaticalRule *s = (GramaticalRule*) malloc(sizeof(GramaticalRule));
    s->next = NULL;
    if (!readRule(arquivoDeEntrada, s))
        return NULL;

    GramaticalRule *currentrule = s;
    GramaticalRule *nextgrule;
    while (!feof(arquivoDeEntrada))
    {
        nextgrule = (GramaticalRule*) malloc(sizeof(GramaticalRule));
        nextgrule->next = NULL;

        if (!readRule(arquivoDeEntrada, nextgrule))
            break;

        while (currentrule->next != NULL)
            currentrule = currentrule->next;

        currentrule->next = nextgrule;
        currentrule = nextgrule;
    }

    fclose(arquivoDeEntrada);
    return s;
}

int readRule(FILE *arquivoDeEntrada, GramaticalRule  *gRule) {


    int c;
    int key = fgetc(arquivoDeEntrada);

    if (!isupper(key))
        return 0;

    gRule->key = (char)key;
    gRule->rule = (char*) malloc(TAMANHO_MAXIMO_DA_REGRA);
    strcpy(gRule->rule, "");

    int sep = fgetc(arquivoDeEntrada);
    if (sep != '-')
        return 0;

    int completerule = 0;
    while (!completerule) {
        int ruleLength = 0;
        while (!feof(arquivoDeEntrada) && (c = fgetc(arquivoDeEntrada)) != '|' && c != '\n' && c != EOF &&
               ruleLength < TAMANHO_MAXIMO_DA_REGRA - 1) {
            memcpy(&gRule->rule[ruleLength], &c, 1);
            ruleLength++;
        };

        if (ruleLength >= TAMANHO_MAXIMO_DA_REGRA - 1)
            return 0;

        memcpy(&gRule->rule[ruleLength], "", 1);

        if (c == '|') {
            GramaticalRule *nextgRule = (GramaticalRule*) malloc(sizeof(GramaticalRule));
            nextgRule->key = gRule->key;
            nextgRule->rule = (char*) malloc(TAMANHO_MAXIMO_DA_REGRA);
            strcpy(nextgRule->rule, "");
            nextgRule->next = NULL;
            gRule->next = nextgRule;
            gRule = nextgRule;
            continue;
        }

        completerule = 1;
    };

    //(*initial) = gRule;

    return 1;
}



