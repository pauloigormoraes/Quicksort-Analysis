#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "functions.h"

int main(int argc, char *argv[]){
    short unsigned opcao;
    int unsigned aux;

    do{
        system("clear");
        setlocale(LC_ALL, "portuguese");
        printf("\n [*] -- Escolha uma opção -- [*]\n\n");
        puts("  1: Ordenação Manual");
        puts("  2: Ordenação Atomática (testes)");
        puts("  0: Sair");
        printf("\n [<]: ");
        scanf("%d", &opcao);
        system("clear");

        printf("\n [>] Informe um tamanho para o vetor: \n [<]: ");
        scanf("%d", &aux);

        switch(opcao){
            case 1:
                sort_manual(aux);
                break;
            case 2:
                //sort_automatic(aux);
                break;
            case 3:
                break;
            default:
                exit(1);
        }
    }while(opcao != 0);

    getchar();
    return 0;
}