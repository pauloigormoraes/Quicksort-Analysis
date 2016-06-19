#include <stdio.h>
<<<<<<< HEAD
#define _tam 12

int separa(int v[], int p, int r) {
	int c = v[p], i = p+1, j = r, t;
	while (1){
	while (i <= r && v[i] <= c) ++i;
    	while (c < v[j]) --j;
    	if (i >= j) break;
    	t = v[i], v[i] = v[j], v[j] = t;
    	++i; --j;
   }
   v[p] = v[j], v[j] = c;
   return j;

}
void quicksort(int v[], int p, int r){
	int j;
	if (p < r){
		j = separa (v, p, r);
		quicksort (v, p, j-1);
		quicksort (v, j+1, r);
	}
}

int main(int argc, char *argv[]){
	int i, dados[_tam] = {5, 100, 0, 1, 4, 1, 100000, 0, 2, 3, 0, 15012000000};

	quicksort(dados, 0, _tam-1);

	for(i=0; i<_tam; i++)
		printf("%d ", dados[i]);

	puts("");

	return 0;
}
=======
#include <stdlib.h>
#include <time.h>
#define DP 10

//Declarando funcoes
void f_quicksort(int *r, int start, int end);
int f_fracture(int *r, int start, int end);
int f_valuetwo (int *d);
int f_having (int *d, int r);

//funcao principal
int main(void) {
  //int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  //int array[10] = {900, 1000, 2, 100000, 5, 7, 3, 4, 1};
  int array[10] = {1, 9, 8, 7, 9, 5, 4, 3, 2, 1};         //declaracao vetor para ordenacao
  int i;                                                 
  printf("\nQuicksort em C\n\n");
  printf("Vetor desordenado\n");
  
	for(i=0; i<10; i++)                                        //imprimindo vetor desordenado
		printf("%i ", array[i]);                               
	
	f_quicksort(array, 0, 9);                                  //passando vetor para funcao quebra do vetor em duas partes
	
	puts("\n\nVetor ordenado");      
	for(i=0; i<10; i++)                                        //imprimindo vetor ordenado
		printf("%i ", array[i]);

	puts("");
	return 0;
}

void f_quicksort(int *r, int start, int end) {
  int key;
  if (end > start) {                                            //condicao de parada (recursivo)
     key = f_fracture(r, start, end);                           //recebendo dados ordenados enviados para funcao de busca na separacao do vetor
           f_quicksort(r, start, key-1);                          //quebra da funcao em duas partes, do inicio do vetor ate a chave 
           f_quicksort(r, key+1, end);                          //e da chave + 1 ate o final do vetor
  }
}

int f_fracture(int *r, int start, int end) {
  int left = start;
  int right = end;
  int key = (start + end) / 2;                                  //declarando um valor inicial para a chave, inteiro pois de um valor e nao de endereco
  int dr = 0;
  while(left <= right){                                         //entrando no laco, o valor do final eh menor que o inicial
    while(r[left] < r[key]) left++;                             //varro comparando a chave com todos os elementos a esquerda
	while(r[right] > r[key]) right--;                           //varro comparando a chave com todos os elementos da direita
	   if(left <= right){                                       //se o valor final for menor ou igual eu faco a troca de posicaoes
	       dr = r[right];                                        //minha variavel recebe o maior valor
               r[right] = r[left];                                  //faco minha posicao inicial receber o menor valor
	       r[left] = dr;                                       //depois faco minha posicao final receber o maior valor
		 left++;                                                //incremento da esquerda
		 right--;                                               //decremento da direita
	   }
  }
 return key;                                                    //retorno o valor ordenado
}
>>>>>>> 7855db40831d326c96284b209a0d085dc59027d7
