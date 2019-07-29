#include <stdio.h>
#include <algorithm>
int n, m, k;
int main() {
	scanf("%d %d %d", &n, &m, &k);
	
	printf("%d", min({ n/2, m, (n+m-k)/3 }));
	return 0;
}
