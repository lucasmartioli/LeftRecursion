//
// Created by Lucas on 10/12/2016.
//

#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include "readgramar.h"

GramaticalRule* readgramar(char *filename)
{
    FILE *arquivoDeEntrada = fopen(filename, "rt");

    if (arquivoDeEntrada == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
        return 0;
    }

    GramaticalRule *s = (GramaticalRule*) malloc(sizeof(GramaticalRule));
    GramaticalRule *gRule = s;
    while (!feof(arquivoDeEntrada))
    {
        gRule->key = (char)fgetc(arquivoDeEntrada);
        gRule->rule = (char*) malloc(500);

        int sep = fgetc(arquivoDeEntrada);
        if (sep != '-')
            return NULL;

        int ruleLength = 0;
        int c;
        while (!feof(arquivoDeEntrada) && (c = fgetc(arquivoDeEntrada)) != '|' && c != '\n' && c != EOF && ruleLength < 499) {
            memcpy(&gRule->rule[ruleLength], &c, 1);
            ruleLength++;
        };

        if(c == EOF)
            break;

        GramaticalRule *nextgRule = (GramaticalRule*) malloc(sizeof(GramaticalRule));
        gRule->next = nextgRule;
        gRule = nextgRule;
    }

    gRule->next = NULL;

    fclose(arquivoDeEntrada);
    return s;
}


