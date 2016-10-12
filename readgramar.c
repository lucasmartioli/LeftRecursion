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
    if (!readRule(arquivoDeEntrada, s))
        return NULL;

    GramaticalRule *gRule = s;
    while (!feof(arquivoDeEntrada))
    {
        GramaticalRule *nextgRule = (GramaticalRule*) malloc(sizeof(GramaticalRule));

        if (!readRule(arquivoDeEntrada, nextgRule))
            break;

        gRule->next = nextgRule;
        gRule = nextgRule;


    }

    gRule->next = NULL;

    fclose(arquivoDeEntrada);
    return s;
}

int readRule(FILE *arquivoDeEntrada, GramaticalRule* gRule) {

    int c;
    int key = fgetc(arquivoDeEntrada);

    if(!isupper(key))
        return 0;

    gRule->key = (char)key;
    gRule->rule = (char*) malloc(500);
    strcpy(gRule->rule, "");

    int sep = fgetc(arquivoDeEntrada);
    if (sep != '-')
        return 0;

    int ruleLength = 0;
    while (!feof(arquivoDeEntrada) && (c = fgetc(arquivoDeEntrada)) != '|' && c != '\n' && c != EOF && ruleLength < TAMANHO_MAXIMO_DA_REGRA - 1) {
        memcpy(&gRule->rule[ruleLength], &c, 1);
        ruleLength++;
    };

    if(ruleLength >= TAMANHO_MAXIMO_DA_REGRA - 1)
        return 0;

    memcpy(&gRule->rule[ruleLength], "", 1);
    return 1;
}



