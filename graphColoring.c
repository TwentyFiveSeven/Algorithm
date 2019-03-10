#include<stdio.h>
#include<stdlib.h>

int n;
int m;
int **W;
int *vcolor;

int promising(int i){
  int j;
  int swit;
  swit = 1;
  j=1;
  while(j<i&&swit){
    if(W[i][j]&&vcolor[i]==vcolor[j])
      swit = 0;
    j++;
  }
  return swit;
}

void M_coloring(int i){
  int color;
  if(promising(i)){
    if(i==n){
      printf("Vcolor : ");
      for(int k=1;k<n+1;k++){
        printf("%d ",vcolor[k]);
      }
      printf("\n");
    }else{
      for(color =1; color <=m; color++){
        vcolor[i+1] = color;
        m_coloring(i+1);
      }
    }
  }
}

int main(){

  scanf("%d %d",&n,&m);
  W = (int **)malloc(sizeof(int*)*(n+1));
  for(int i=0; i<=n;i++){
    W[i] = (int *)malloc(sizeof(int)*(n+1));
    for(int j=0; j<=n;j++){
      
    }
  }

  int **W;
  int *vcolor;
}
