//
// Created by Lucas on 10/12/2016.
//

#ifndef PREDICTIONTABLE_READGRAMAR_H
#define PREDICTIONTABLE_READGRAMAR_H

#include <stdio.h>

    struct gramaticalrule
    {
        struct gramaticalrule *next;
        char *rule;
        char key;
    };

    typedef struct gramaticalrule GramaticalRule;

    //int openfile(char *filename, FILE *arquivoDeEntrada);
    GramaticalRule* readgramar(char *filename);
    int readRule(FILE *arquivoDeEntrada, GramaticalRule* gRule);


#endif //PREDICTIONTABLE_READGRAMAR_H
