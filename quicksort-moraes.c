#include <stdio.h>
//Declarando funcoes
void f_quicksort(int *r, int start, int end);
int f_fracture(int *r, int start, int end);
//funcao principal
int main(void) {
  int array[10] = {2, 390, 34, 9, 0, 40, 6, 8, 45, 1};         //declaracao vetor para ordenacao
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
           f_quicksort(r, start, key);                          //quebra da funcao em duas partes, do inicio do vetor ate a chave 
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
	       dr = r[left];                                        //minha variavel recebe o maior valor
           r[left] = r[right];                                  //faco minha posicao inicial receber o menor valor
		   r[right] = dr;                                       //depois faco minha posicao final receber o maior valor
		 left++;                                                //incremento da esquerda
		 right--;                                               //decremento da direita
	   }
  }
 return key;                                                    //retorno o valor ordenado
}
