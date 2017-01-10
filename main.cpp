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
        std::cout << "Parametros de entrada: <arquivo de entrada> [arquivo de saida]='" + nomearquivodesaida + "'" << std::endl;
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

    std::cout << "Resposta do programa esta no arquivo: " + nomearquivodesaida << std::endl;

    return true;
}