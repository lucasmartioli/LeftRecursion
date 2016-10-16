//
// Created by sutil on 13/10/16.
//

#include <malloc.h>
#include "readgrammar.h"

#include "conjunto.h"

Conjunto *follow(GrammarRule *gramaticalRules) {
    char key = gramaticalRules->key;
    while(key != NULL){
        gramaticalRules++;
        key = gramaticalRules->key;
        printf("follow");
        printf("%s", key);
    }

    return NULL;
}
