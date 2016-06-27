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

/*-- Procedimento responsável por ordenar valores de um vetor
 *   informado pelo usuário.
 * */
void sort_manual(int unsigned vector_length){
    int i, *vet = setLength(vector_length);
    clock_t begin, end;
    double total;

    printf("\n [<] Entre com valores para o vetor: \n\n");
    for(i=0; i<vector_length; i++){
        printf("   v[%d]: ", i);
        scanf("%d", &vet[i]);
    }

    printf("\n [>] Seu vetor não ordenado é: ");
    for(i=0; i<vector_length; i++)
        printf("%d ", vet[i]);

    begin = clock(); //Armazena o tempo de início de processamento da função quicksort
    quicksort(vet, 0, vector_length-1); //Chamada da função QuickSort
    end = clock(); //Obtém o tempo de fim da função quicksort

    total = (double) (end - begin)/CLOCKS_PER_SEC; //Calcula a diferença de tempos e converte para segundos

    printf("\n [>] Após a aplicação do 'quicksort', seu vetor é: ");
    for(i=0; i<vector_length; i++)
        printf("%d ", vet[i]);

    printf("\n [!] Ordenação realizada em %f segundos.", total);
    printf("\n\n [!] Pressione a tecla 'Enter' para continuar...");
    while(getchar()!='\n');
    getchar();
    free(vet);
}

void sort_automatic(int unsigned vector_length){
    int i, max, *vet = setLength(vector_length);
    unsigned short int option, aux;
    clock_t begin, end;
    double total;

    printf("\n [>] Informe o valor máximo presente no vetor: \n [<]: ");
    scanf("%d", &max);

    printf("\n [>] Como você deseja pré ordenar os valores?\n\n");
    puts("\t1: Totalmente pseudoaleatórios");
    puts("\t2: Em ordem crescente");
    puts("\t3: Em ordem decrescente");
    printf("\n [<]: ");
    scanf("%hu", &aux);

    // Atribuição de valores pseudoaleatórios ao vetor
    srand((unsigned int) time(NULL));
    for(i=0; i<vector_length; i++)
        vet[i] = 0 + (rand() % max); // de 0 até 'max' (um valor informado pelo usuário)

    if(aux == 2){
        quicksort(vet, 0, vector_length-1);
        printf("\n [!] Assumindo Opção 2: Valores pseudoaleatórios em ordem crescente.");
    }else if(aux == 3){
        quicksort(vet, 0, vector_length-1);
        int j, *auxVet = setLength(vector_length);
        auxVet = vet;
        for(i=vector_length-1, j=0; i>=0; i--, j++)
            vet[j] = auxVet[i];

        printf("\n [!] Assumindo Opção 3: Valores pseudoaleatórios em ordem decrescente.");
    }else
        printf("\n [!] Assumindo Opção 1: Valores totalmente pseudoaleatórios desordenados.");

    begin = clock(); //Armazena o tempo de início de processamento da função quicksort
    quicksort(vet, 0, vector_length-1); //Chamada da função QuickSort
    end = clock(); //Obtém o tempo de fim da função quicksort

    total = (double) (end - begin)/CLOCKS_PER_SEC; //Calcula a diferença de tempos e converte para segundos
    printf("\n [!] O tempo de ordenação de %d valores pseudoaleatórios foi de %f segundos.\n [>] Deseja listar os valores? (1: Sim | 0: Não)\n [<]: ", vector_length, total);
    scanf("%hu", &option);
    puts(" ");

    if(option == 1){
        printf("[>] Valores pseudoaleatórios após a aplicação do 'quicksort': ");
        for(i=0; i<vector_length; i++)
            printf("%d ", vet[i]);
    }

    printf("\n\n [!] Pressione a tecla 'Enter' para continuar...");
    while(getchar()!='\n');
    getchar();
    free(vet);
}
