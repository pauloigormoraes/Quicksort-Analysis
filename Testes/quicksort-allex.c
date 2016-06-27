#include <stdio.h>
#define _tam 12

static int divide(int *v, int begin, int end){
    int i = begin + 1,      //Recebe a segunda posição do vetor
        j = end,        //Recebe a última posição do vetor
        pivo = begin,   //Pivo/Base inicial
        aux;    //Variável auxiliar

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


void quicksort(int *v, int begin, int end){
    if(begin < end){
        int pivo = divide(v, begin, end);
        quicksort(v, begin, pivo-1);
        quicksort(v, pivo+1, end);
    }
}	

int main(int argc, char *argv[]){
	int i, dados[_tam] = {0, 100, 0, 1, 6, 1, 100000, 0, 2, 3, 0, 15012000};

	quicksort(dados, 0, _tam-1);

	for(i=0; i<_tam; i++)
		printf("%d ", dados[i]);

	return 0;
}
