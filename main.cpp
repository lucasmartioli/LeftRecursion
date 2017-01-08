//
// Created by Lucas on 11/10/2016.
//

#include <iostream>
#include "readgrammar.h"
#include "lrecursionpurge.h"

using namespace std;

int main(int ac, char *av[])
{

    string nomearquivodesaida ("gramatica_saida.txt");
    string nomearquivodeentrada ("");

    if (ac < 2 || ac > 3)
    {
        std::cout << "<arquivo de entrada> [arquivo de saida]" << std::endl;
        return false;
    }

    nomearquivodeentrada = av[1];
    if (ac == 3)
        nomearquivodesaida = av[2];

    GrammarRule* s = readgrammar(av[1]);
    if (!s)
    {
        std::cout << "Problemas na leitura da gramatica. Verifique o formato de entrada!" << std::endl;
        return false;
    }

    if (!lrecursionpurge(s, nomearquivodesaida)){
        std::cout << "Erro ao tentar retirar recursões a esquerda da gramatica apresentada!" << std::endl;
        return false;
    }

    return true;
}
//
//int writefollowset(FollowSet *followset)
//{
//    FILE *followfile = fopen("follow.txt", "w");
//
//    if (followfile == NULL) {
//        printf("Problemas na criação do arquivo follow\n");
//        return 0;
//    }
//
//    while (followset != NULL) {
//        char *desc1 = "Conjunto: ";
//        char *notterminal = (char *) malloc(2);
//        notterminal[0] = followset->key;
//        notterminal[1] = '\0';
//        char *desc2 = " = {";
//
//        if (fwrite(desc1, 1, strlen(desc1), followfile) != strlen(desc1) ||
//            fwrite(notterminal, 1, 1, followfile) != 1 ||
//            fwrite(desc2, 1, strlen(desc2), followfile) != strlen(desc2) ||
//            fwrite(followset->set, 1, strlen(followset->set), followfile) != strlen(followset->set) ||
//            fwrite("}\n", 1, 2, followfile) != 2) {
//            printf("Erro na escrita do arquivo");
//            return 0;
//        }
//        followset = followset->next;
//    }
//
//    fclose(followfile);
//    return 1;
//}

