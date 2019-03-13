#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int M(int i, int j);
void order(int i, int j);

int* d;
int count=0;
int** P;

void order(int i, int j){
  int k =0;
  if(i == j){
    printf("A%d",i);
  }else{
    k = P[i][j];
    printf("(");
    order(i,k);
    order(k+1,j);
    printf(")");
  }
}

int M(int i, int j){
  int save =0;
  int k=i;
  count++;
  if(i==j){
    return 0;
  }
  else if(j-i ==1){
    P[i][j]=k;
    return d[i-1]*d[i]*d[j];
  }else{
    save =M(i,i)+M(i+1,j)+d[i-1]*d[i]*d[j];
    for(k=i;k<=j-1;k++){
      if(M(i,k)+M(k+1,j)+d[i-1]*d[k]*d[j]<=save){
        save = M(i,k)+M(k+1,j)+d[i-1]*d[k]*d[j];
        P[i][j]=k;
      }
    }
    return save;
  }
}

int main(){
  int n=0;
  int last=0;

  printf("Number of input : ");
  scanf("%d",&n);

  d = (int*)malloc(sizeof(int)*(n+1));
  P = (int**)malloc(sizeof(int*)*(n+1));
  for(int i =0; i<n+1;i++){
    P[i]=(int*)malloc(sizeof(int)*(n+1));
  }

  for(int i=0; i<n+1;i++){
    for(int j=0; j<n+1;j++){
      P[i][j]=0;
    }
  }

  printf("low,column of matrix : \n");
  for(int i=0; i<n;i++){
    scanf("%d %d",&d[i],&last);
    if(i == n-1){
      d[n] =last;
    }
  }
  printf("Number of Minimum Multiple : %d\n", M(1,n));
  printf("time : %d \n",count);

  for(int i=1; i<n;i++){
    if(i==1){
      printf("P:  ");
    }
    for(int j=2;j<n+1;j++){
      if(P[i][j]==0){
        printf("  ");
      }else{
      printf("%d ",P[i][j]);
      }
    }
    if(i==n-1){
      printf("\n");
    }else{
    printf("\n    ");
    }
  }
  printf("Order : ");
  order(1,n);
  return 0;
}
