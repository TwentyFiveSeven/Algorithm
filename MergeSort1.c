#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void merge(int h, int m, int* U, int* V, int S[]) {
	int i, j,v,u,k;
	i = 0; j = 0,k=0;
	while (i < h && j < m) {
		if (U[i] < V[j]) {
			S[k++] = U[i];
			i++;
		}
		else {
			S[k++] = V[j];
			j++;
		}
	}
	if (i >= h)//copy V[j] through V[m] to S[k] through S[h + m];
		for(v = j; v < m; v++) {
			S[k++] = V[v];
		}
	else {//copy U[i] through U[h] to S[k] through S[h + m];
		for (u = i; u < h; u++) {
			S[k++] = U[u];
		}
	}
}


void mergesort(int n, int S[]) {
	const int h = n / 2, m = n - h;
	int* U = (int*)malloc(sizeof(int)*h);
	int* V = (int*)malloc(sizeof(int)*m);

	memset(U, 0, sizeof(int)*h);
	memset(V, 0, sizeof(int)*m);

	if (n > 1) {
		for (int i = 0; i < n; i++) {
			if (i < h) {	//copy S[1] through S[h] to U[1] thorough U[h];
				U[i] = S[i];
			}
			else {	//copy S[h + 1] through S[n] to V[1] through V[m];
				V[i - h] = S[i];
			}
		}
		mergesort(h, U);
		mergesort(m, V);
		merge(h, m, U, V, S);

		free(U);
	  free(V);
	}
}


int main() {
	int n = 0;

	scanf("%d", &n);
	int* S = (int*)malloc(sizeof(int)*n);

  for(int i=0; i<n;i++){
    scanf("%d",&S[i]);
  }
	mergesort(n, S);
}
