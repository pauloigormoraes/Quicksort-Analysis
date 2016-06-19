#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Declarando funcoes
void f_quicksort(int *r, int start, int end);
int f_fracture(int *r, int start, int end);
int f_valuetwo (int *d, int m);
int f_having (int *d, int r, int m);

//funcao principal
int main(void) {
  int i, d;   
                                              
  printf("\nQuicksort em C\n\n");

  printf("Entre com o numero de elementos a serem ordenados: ");
  scanf("%i", &d);
  printf("Integrantes %i\n", d);
  int array[d];
  
  puts("Vetor desordenado > ");
  for(i = 0; i < d; i++) {
  array[i] = f_valuetwo(array, d);
  printf("%i ", array[i]);
  }
  puts("");

  f_quicksort(array, 0, d-1);

  puts("\nVetor ordenado > ");
  for(i = 0; i < d; i++) {
  printf("%i ", array[i]);
  }
	puts("");
	return 0;
}

void f_quicksort(int *array, int start, int end) {
  int key;
  if (start < end) {
           key = f_fracture(array, start, end);              
           f_quicksort(array, start, key-1); 
           f_quicksort(array, key+1, end);               
  }
}

int f_fracture(int *array, int start, int end) {
   int key = array[start];
   //int key = (start + end) / 2;
   int left = start+1;
   int right = end;
   int dr;
	while (1){
	while (left <= end && array[left] <= key) left++;
    	while (key < array[right]) right--;
    	if (left >= right) break;
    	dr = array[left];
        array[left] = array[right];
        array[right] = dr;
  
    	left++; 
        right--;
   }
   array[start] = array[right];
   array[right] = key;
   return right;
}

int f_valuetwo(int *d, int m) { 
  int r;
  srand((unsigned int)time(NULL));
  do {
      r = 1 + (rand() % m);
  }
  while (f_having(d, r, m)); 
  return r; 
}

int f_having (int *d, int r, int m) {
  int i;
  for(i = 0; i < m; i++) {                     
   if (d[i] == r) return 1;
  }
  return 0;
}
