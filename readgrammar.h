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

    typedef struct gramaticalrule GrammarRule;

    GrammarRule* readgrammar(char *filename);
    int readRule(FILE *arquivoDeEntrada, GrammarRule* gramarrule);


#endif //PREDICTIONTABLE_READGRAMAR_H
