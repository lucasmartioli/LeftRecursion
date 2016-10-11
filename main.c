//
// Created by Lucas on 11/10/2016.
//

#include <stdio.h>
//#include <conio.h>

int main(int argc, char *argv[])
{
    printf("Quantidade de parametros de entrada: %d\n", argc);
    if (argc != 2)
    {
       printf("Deve ser passado o nome do arquivo de entrada como parametro de execucao. Apenas o nome do arquivo de entrada.\n");
       return 0;
    }

    FILE *arquivoDeEntrada;
    int tamanhoMinimoDaLinha = 100;
    char Linha[tamanhoMinimoDaLinha];
    char *result;
    int i;
    //clrscr();

    arquivoDeEntrada = fopen(argv[1], "rt");
    if (arquivoDeEntrada == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
        return 0;
    }

    i = 1;
    while (!feof(arquivoDeEntrada))
    {
        // Lê uma linha (inclusive com o '\n')
        result = fgets(Linha, tamanhoMinimoDaLinha, arquivoDeEntrada);
        if (result)  // Se foi possível ler
            printf("Linha %d : %s",i,Linha);
        i++;
    }
    fclose(arquivoDeEntrada);
    return 1;
}

