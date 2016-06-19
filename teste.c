#include <stdio.h>
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