#include<stdio.h>

int bin2(int n,int k){
  int i,j,min;
  int B[k+1];
  int mink=0;
  for(int i=0; i<n+1;i++){
      B[i]=0;
  }
  for(i=0;i<=n;i++){
    if(i<k){
      min = i;
    }else{
      min =k;
    }
     B[i]=1;
    if(min%2==1){
      mink=min/2+1;
    }else{
      mink=min/2;
    }
    for(j=min;j>=mink;j--){
      if(j==i){
        B[j]=1;
      }else{
        B[j] = B[j]+B[j-1];
      }
    }
    for(int p=min-1;p>=mink;p--){
      B[min-p]=B[p];
    }
    B[i-j] =B[j];
    for(int j=0; j<n+1;j++){
      printf("%d ",B[j]);
    }
  printf("\n\n");
  }

    for(int j=0; j<n+1;j++){
      printf("%d ",B[j]);
    }
  printf("\n\n");
  return B[k];
}


int main(){
  int inputi,inputj;

  scanf("%d %d",&inputi,&inputj);

  printf("%d",bin2(inputi,inputj));
  return 0;

}
