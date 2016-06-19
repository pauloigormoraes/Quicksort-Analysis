#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*-- Função que retorna um valor 'x' tal que
 *   v[begin .. x-1] < v[x] < v[x+1 .. end]
 * */
static int divide(int *v, int begin, int end){
    int i = begin + 1,      //Recebe a segunda posição do vetor
            j = end,        //Recebe a última posição do vetor
            pivo = begin,   //Pivo/Base inicial
            aux;            //Variável auxiliar

    while(i <= j){
        if(v[pivo] >= v[i])
            i++;
        else if(v[pivo] < v[j])
            j--;
        else{
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
            i++;
            j--;
        }
    }

    aux = v[pivo];
    v[pivo] = v[j];
    v[j] = aux;

    return j;
}

/*-- Função quicksort
 *   Após obter o valor do pivo, com a função 'divide',
 *   ordena recursivamente as partes v[begin .. x-1] e v[x+1 .. end]
 *   enquanto begin < end.
 * */
void quicksort(int *v, int begin, int end){
    if(begin < end){
        int pivo = divide(v, begin, end); //Obtém um valor x (pivo) tal que v[begin .. x-1] < v[x] < v[x+1 .. end]
        quicksort(v, begin, pivo-1);
        quicksort(v, pivo+1, end);
    }
}

/*-- Função responsável por alocar dinâmicamente um vetor com 'len' posições de inteiros.
 * */
int *setLength(int len){
    return (int *) malloc(sizeof(int) * len);
}

void sort_manual(int unsigned vector_length){
    int i, *vet = setLength(vector_length);

    printf("\n [<] Entre com valores para o vetor: \n\n");
    for(i=0; i<vector_length; i++){
        printf("   v[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    printf("\n [>] Seu vetor não ordenado é: ");
    for(i=0; i<vector_length; i++)
        printf("%d ", vet[i]);

    quicksort(vet, 0, vector_length-1);

    printf("\n [>] Após a aplicação do 'quicksort', seu vetor é: ");
    for(i=0; i<vector_length; i++)
        printf("%d ", vet[i]);

    printf("\n\n [!] Pressione a tecla 'Enter' para continuar...");
    while(getchar()!='\n');
    getchar();
    free(vet);
}
