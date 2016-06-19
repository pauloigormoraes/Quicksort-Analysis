#include <stdio.h>
#define _tam 10

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
void quicksort(int *v, int begin, int end){
	if(begin < end){
		int pivo = separa(v, begin, end);
		quicksort(v, begin, pivo);
		quicksort(v, pivo+1, end);
	}
}	

int main(int argc, char *argv[]){
	int i, dados[_tam] = {5, 100, 0, 1, 4, 1, 100000, 0, 2, 3};

	quicksort(dados, 0, _tam-1);

	for(i=0; i<_tam; i++)
		printf("%d ", dados[i]);

	puts("");

	return 0;
}
