//
// Created by Lucas on 10/12/2016.
//

#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include "readgramar.h"
#include "grammar.h"

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

    GramaticalRule *currentgrammarrule = s;
    GramaticalRule *nextgrammarrule;
    while (!feof(arquivoDeEntrada))
    {
        nextgrammarrule = (GramaticalRule*) malloc(sizeof(GramaticalRule));
        nextgrammarrule->next = NULL;

        if (!readRule(arquivoDeEntrada, nextgrammarrule))
            break;

        while (currentgrammarrule->next != NULL)
            currentgrammarrule = currentgrammarrule->next;

        currentgrammarrule->next = nextgrammarrule;
        currentgrammarrule = nextgrammarrule;
    }

    fclose(arquivoDeEntrada);
    return s;
}

int readRule(FILE *arquivoDeEntrada, GramaticalRule  *gramarrule) {


    int currentchar;
    int key = fgetc(arquivoDeEntrada);

    if (!isupper(key))
        return 0;

    gramarrule->key = (char)key;
    gramarrule->rule = (char*) malloc(TAMANHO_MAXIMO_DA_REGRA);
    strcpy(gramarrule->rule, "");

    int separator = fgetc(arquivoDeEntrada);
    if (separator != '-')
        return 0;

    while (true) {
        int ruleLength = 0;
        while (!feof(arquivoDeEntrada) && (currentchar = fgetc(arquivoDeEntrada)) != '|' && currentchar != '\n' && currentchar != EOF &&
               ruleLength < TAMANHO_MAXIMO_DA_REGRA - 1) {
            memcpy(&gramarrule->rule[ruleLength], &currentchar, 1);
            ruleLength++;
        };

        if (ruleLength >= TAMANHO_MAXIMO_DA_REGRA - 1)
            return 0;

        memcpy(&gramarrule->rule[ruleLength], "", 1);

        if (currentchar == '|') {
            GramaticalRule *nextgrammarrule = (GramaticalRule*) malloc(sizeof(GramaticalRule));
            nextgrammarrule->key = gramarrule->key;
            nextgrammarrule->rule = (char*) malloc(TAMANHO_MAXIMO_DA_REGRA);
            strcpy(nextgrammarrule->rule, "");
            nextgrammarrule->next = NULL;
            gramarrule->next = nextgrammarrule;
            gramarrule = nextgrammarrule;
            continue;
        }

        break;
    };

    return 1;
}



