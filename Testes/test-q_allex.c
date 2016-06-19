#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(int *v, int begin, int end){

	/* Caso Base: Condição de parada da recursão
	 * */

	if(begin >= end)
		return;

	int pivo = end,		//Pivô: Valor central do vetor
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
	
	quicksort(v, begin, pivo-1);
	quicksort(v, pivo+1, end);

}

int main(int argc, char *argv[]){
	int i, tam, *array;	
	
	if(argc > 1){
		if(strcmp(argv[1], "-h") == 0)
			printf("Para realizar os testes automaticos de ordenacao pelo metodo Quicksort, voce deve informar um vetor. \n\t %s <int array>\t -v <int array> eh um conjunto de numeros desordenados, por exemplo 34202.\n", argv[0]);	
		else if(strcmp(argv[1], "-v") == 0){
			tam = strlen(argv[2]);
			array = (int *) malloc(sizeof(int) * tam);

			for(i=0; i<tam; i++)
				array[i] = (int) argv[2][i] - 48;
			
			quicksort(array, 0, tam-1);	

			printf("Vetor ordenado: ");
			for(i=0; i<tam; i++)
				printf("%d ", array[i]);
					
			puts("");
			
		}else
			printf("Erro: '%s' nao eh um parametro valido. Use '-h' para obter ajuda.\n", argv[1]);
	}else
		printf("Parametros nao identificados. Use '-h' para obter ajuda.\n");

	return 0;
}
