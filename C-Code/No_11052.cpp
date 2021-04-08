#include<iostream>

int Price[10001];
int max[10001];
int main(){
    int n=0,i,j;

    scanf("%d",&n);

    for(i=1;i<=n;i++){
      scanf("%d",&Price[i]);
    }

    for(i=1;i<=n;i++){
      for(j=1;j<=i;j++){
        if(max[i]<Price[j]+max[i-j])
          max[i] = Price[j]+max[i-j];
          printf("j = %d,i-j =%d, max[%d] = %d\n",j,i-j,i,max[i]);
      }
    }
    printf("%d",max[n]);
}
