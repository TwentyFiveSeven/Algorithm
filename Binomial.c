#include<stdio.h>

int bin2(int n,int k){
  int i,j,min;
  int B[n+1][k+1];
  for(int i=0; i<n+1;i++){
    for(int j=0; j<k+1;j++){
      B[i][j]=0;
    }
  }
  for(i=0;i<=n;i++){
    if(i<k){
      min = i;
    }else{
      min =k;
    }
    for(j=0;j<=min;j++){
      if(j==0||j==i){
        B[i][j] =1;
      }else{
        B[i][j] = B[i-1][j-1]+B[i-1][j];
      }
    }
  }

  for(int i=0; i<n+1;i++){
    printf("\n");
    for(int j=0; j<k+1;j++){
      printf("%d ",B[i][j]);
    }
  }
  printf("\n\n");
  return B[n][k];
}


int main(){
  int inputi,inputj;

  scanf("%d %d",&inputi,&inputj);

  printf("%d",bin2(inputi,inputj));
  return 0;

}
