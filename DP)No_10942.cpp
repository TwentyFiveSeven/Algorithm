#include<iostream>
using namespace std;
int arr[2001],dp[2001][2001];
int main(){
  int N,M,S,E;
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d",&arr[i]);
    dp[i][i] = 1;
  }
  for(int i=N-1;i>=1;i--){
    for(int j= i+1;j<=N;j++){
      if(j-i<=2){
        dp[i][j] = 1 && (arr[i] == arr[j]);
      }else{
        dp[i][j] = dp[i+1][j-1] && (arr[i] == arr[j]);
      }
    }
  }
  scanf("%d",&M);
  while(M--){
    scanf("%d %d",&S,&E);
    printf("%d\n",dp[S][E]);
  }
  return 0;
}
