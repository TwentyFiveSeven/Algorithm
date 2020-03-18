#include<iostream>
using namespace std;

int N,K,arr[1000][1000];

int main(){
  scanf("%d %d",&N,&K);
  if(K > N/2){
    printf("0");
    return 0;
  }
  arr[0][0] = 1; arr[1][0] =2; arr[2][0] = 3;
  for(int i=3;i<N;i++){
    arr[i][0] = i+1;
    for(int j=1;j<K;j++){
      arr[i][j] = (arr[i-1][j] + arr[i-2][j-1])%1000000003;
    }
  }
  printf("%d",arr[N-1][K-1]);
  return 0;
}
