//
// Created by Lucas on 10/12/2016.
//

#ifndef PREDICTIONTABLE_READGRAMAR_H
#define PREDICTIONTABLE_READGRAMAR_H

    #include <stdio.h>

    #define CARACTER_VAZIO '*'
    #define CARACTER_FINAL_ARQUIVO '$'

    struct gramaticalrule
    {
        struct gramaticalrule *next;
        char *rule;
        char key;
    };

    typedef struct gramaticalrule GramaticalRule;

    GramaticalRule* readgramar(char *filename);
    int readRule(FILE *arquivoDeEntrada, GramaticalRule* gramarrule);


#endif //PREDICTIONTABLE_READGRAMAR_H
