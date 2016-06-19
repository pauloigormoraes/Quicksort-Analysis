#include <stdio.h>
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
<<<<<<< HEAD
<<<<<<< HEAD
  int array[11] = {1, 2, 6, 3, 4, 6, 1, 2, 5, 7, 9};         //declaracao vetor para ordenacao
=======
=======
>>>>>>> 7855db40831d326c96284b209a0d085dc59027d7
  int d[DP];
  int array[10] = {2, 390, 34, 9, 0, 40, 6, 8, 45, 1};         //declaracao vetor para ordenacao
>>>>>>> 7855db40831d326c96284b209a0d085dc59027d7
  int i;                                                 
  printf("\nQuicksort em C\n\n");
  puts("Vetor desordenado > ");
  for(i = 0; i <DP; i++){
  d[i] = f_valuetwo(d);
  printf("%i ", d[i]);
  }
  f_quicksort(d, 0, 9);
  puts("\nVetor ordenado > ");
  for(i = 0; i < DP; i++) {
  printf("%i ", d[i]);
  }

  printf("\n\nVetor desordenado\n");
  
	for(i=0; i<11; i++)                                        //imprimindo vetor desordenado
		printf("%i ", array[i]);                               
	
	f_quicksort(array, 0, 10);                                  //passando vetor para funcao quebra do vetor em duas partes
	
	puts("\n\nVetor ordenado");      
<<<<<<< HEAD
<<<<<<< HEAD
	for(i=0; i<11; i++)                                        //imprimindo vetor ordenado
		printf("%i ", array[i]);
=======
	for(i=0; i<10; i++)                                        //imprimindo vetor ordenado
            printf("%i ", array[i]);
>>>>>>> 7855db40831d326c96284b209a0d085dc59027d7
=======
	for(i=0; i<10; i++)                                        //imprimindo vetor ordenado
            printf("%i ", array[i]);
>>>>>>> 7855db40831d326c96284b209a0d085dc59027d7

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

int f_valuetwo(int *d) {                        //funcao para calcular o primeiro valor a ser comparado  
  int r;
  srand((unsigned int)time(NULL));              //iniciando a funcao rand para pegar valores do tempo do pc
  do {
      r = 1 + (rand() % 10);                    //capturando randomicamente valores de 1 ate 10
  }
  while (f_having(d, r));                       //enviando valor capturado em r junto com o valor recebido da main
  return r;                                     //so vai enviar para main quando o valor vindo de f_having for 0
}

int f_having (int *d, int r) {
  int i;
  for(i = 0; i < DP; i++) {                     
   if (d[i] == r) return 1;                     //compara o valor do vetor vindo da main junto ao segundo valor derivado da f_valuetwo
  }                                             //e retornando um booleano 1 = sim; 0 = nao
  return 0;
}
