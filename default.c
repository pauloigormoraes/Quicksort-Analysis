#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "functions.h"

int main(int argc, char *argv[]){
    unsigned short int option, aux;

    do{
        system("clear");
        setlocale(LC_ALL, "portuguese");
        printf("\n [*] -- Escolha uma opção -- [*]\n\n");
        puts("\t1: Ordenação Manual");
        puts("\t2: Ordenação Atomática (testes)");
        puts("\t0: Sair");
        printf("\n [<]: ");
        scanf("%hu", &option);
        system("clear");

        if(option != 0) {
            printf("\n [>] Informe um tamanho para o vetor: \n [<]: ");
            scanf("%hu", &aux);
        }

        switch(option){
            case 1:
                sort_manual(aux);
                break;
            case 2:
                sort_automatic(aux);
                break;
            default:
                exit(1);
        }
    }while(option != 0);

    return 0;
}
