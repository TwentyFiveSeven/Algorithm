#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int n;
int *col;


int promising(int i){
  int k;
  int swit;

  k=1;
  swit = 1;
  while(k<i&&swit){
    if(col[i]==col[k]||abs(col[i]-col[k])==abs(i-k))
      swit = 0;
    k++;
  }
  printf("promising : %d\n",swit);
  return swit;
}

int estimate_n_queens(int n){
  int i,j;
  int m,mprod,numnodes;
  int prom_children[50];

  i=0;numnodes=1; m=1; mprod=1;
  while(m !=0 && i!=n){
    printf("1\n");
    mprod = mprod*m;
    numnodes = numnodes + mprod*n;
    i++; m = 0;
    for(int p = 0; p<50;p++){
      prom_children[p]=0;
    }
    printf("2\n");
    int count =0;
    for(j=1;j<=n;j++){
      col[i] =j;
      if(promising(i)){
        m++;
        prom_children[count++] = j;
      }
    }
    printf("3\n");
    if(m !=0){
      if(m ==1){
        col[i]=prom_children[0];
      }else{
      srand(time(NULL));
      j=prom_children[rand()%(count-1)];
      }
      col[i]=j;
    }
    printf("4\n");
  }
  printf("5\n");
  return numnodes;
}


int main(){
  scanf("%d",&n);
  col = (int*)malloc(sizeof(int)*(n+1));

  for(int i=0; i<=n;i++)
    col[i]=0;
  printf("\n\nn : %d",estimate_n_queens(n));

}
