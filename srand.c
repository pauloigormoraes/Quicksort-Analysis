#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DP 10

int f_valuetwo (int *d);
int f_having (int *d, int r);

int main () {
  int d[DP];                                    //crio meu vetor de tamanho DP
  int i = 0;

  for(i = 0; i < DP; i++) {                     //leio valores um por um
  d[i] = f_valuetwo(d);                         //recebo os valores do vetor
  printf("%i\n", d[i]);                         //imprimo na tela os valores nao repetidos
  }

  return 0;
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
