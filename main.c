//
// Created by Lucas on 11/10/2016.
//

#include <stdio.h>
//#include <conio.h>

void main(int argc, char *argv[])
{

    if (argc != 1)
    {
       printf("Deve ser passado o nome do arquivo de entrada como parametro de execução. Apenas o nome do arquivo de entrada.\n");
       return;
    }

    FILE *arquivoDeEntrada;
    int tamanhoMinimoDaLinha = 100;
    char Linha[tamanhoMinimoDaLinha];
    char *result;
    int i;
    //clrscr();

    arquivoDeEntrada = fopen(*argv, "rt");
    if (arquivoDeEntrada == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
        return;
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
}

