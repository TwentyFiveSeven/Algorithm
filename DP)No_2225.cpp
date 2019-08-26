#include<iostream>
using namespace std;

int arr[201][201],N,K;

int main(){
  int i,j;
  scanf("%d %d", &N,&K);
  for(i=1;i<=K;i++) arr[1][i] =i;
  for(i=2;i<=N;i++){
    for(j=1;j<=K;j++){
      arr[i][j] = (arr[i-1][j]+arr[i][j-1])%1000000000;
    }
  }
  printf("%d",arr[N][K]);
  return 0;
}
