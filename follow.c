//
// Created by sutil on 13/10/16.
//

#include <malloc.h>
#include "readgramar.h"

#include "conjunto.h"

Conjunto *follow(GramaticalRule *gramaticalRules) {
    char key = gramaticalRules->key;
    while(key != NULL){
        gramaticalRules++;
        key = gramaticalRules->key;
        printf("follow");
        printf("%s", key);
    }

    return NULL;
}
