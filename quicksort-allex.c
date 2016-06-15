#include <stdio.h>
#define _tam 6

int getPivo(int *v, int begin, int end);

void quicksort(int *vector, int begin, int end){
	int pivo;
	if(end > begin){
		int pivo = getPivo(vector, begin, end);
		quicksort(vector, begin, pivo);
		quicksort(vector, pivo+1, end);
	}
}

int getPivo(int *v, int begin, int end){
	int pivo = (begin + end)/2, //Pivô: Valor central do vetor
		i = begin, //Extremidade esquerda do vetor
		j = end, //Extremidade direira do vetor
		aux; //Variável auxiliar
	
	while(i <= j){
		while(v[i] < v[pivo])
			i++;
		while(v[j] > v[pivo])
			j--;
		
		if(i <= j){
			aux = v[j];
			v[j] = v[i];
			v[i] = aux;
			i++;
			j--;
		}
	}

	return pivo;	
}

int main(int argc, char *argv[]){
	int i, dados[_tam] = {5, 0, 2, 4, 1, 3};

	quicksort(dados, 0, _tam-1);

	for(i=0; i<_tam; i++)
		printf("%d ", dados[i]);

	return 0;
}
