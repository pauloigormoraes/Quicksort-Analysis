#include <stdio.h>
#define _tam 6

void quicksort(int *v, int begin, int end){

	/* Caso Base: Condição de parada da recursão
	 * */

	if(begin >= end)
		return;

	int pivo = (begin + end)/2,	//Pivô: Valor central do vetor
		i,						//Extremidade esquerda do vetor
		j,						//Extremidade direita do vetor
		aux;					//Variável auxiliar

	/* Parte responsável por organizar todos os elementos menores que o pivô
	 * ao seu lado esquerdo e manter os elementos maiores à direita.
	 * */
	
	for(i=begin, j=end; i <= j; i++, j--){
		while(v[i] < v[pivo])
			i++;
		while(v[j] > v[pivo])
			j--;

		if(i <= j){
			aux = v[j];
			v[j] = v[i];
			v[i] = aux;
		}
	}

	/* Parte recursiva responsável por ordenar as duas segmentações do vetor
	 * (de 'begin' até 'pivo' e de 'pivo+1' até 'end')
	 * */
	
	quicksort(v, begin, pivo);
	quicksort(v, pivo+1, end);

}	

int main(int argc, char *argv[]){
	int i, dados[_tam] = {5, 0, 2, 4, 1, 3};

	quicksort(dados, 0, _tam-1);

	for(i=0; i<_tam; i++)
		printf("%d ", dados[i]);

	return 0;
}
