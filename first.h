//
// Created by Lucas on 10/15/2016.
//

#ifndef PREDICTIONTABLE_FIRST_H
#define PREDICTIONTABLE_FIRST_H

    #include "readgramar.h"

    struct firstset
    {
        struct firstset *next;
        char *set;
        char key;
    };

    typedef struct firstset FirstSet;

    FirstSet *first(GramaticalRule *gramaticalrule);
    FirstSet *seekkey(FirstSet *firstset);
    int containemptyinrule(char *rule);
    void copyrulewithoutempty(char *rulesource, char *ruledestination)

#endif //PREDICTIONTABLE_FIRST_H
