#include<iostream>
#include<algorithm>
using namespace std;

int grape[10001];
int dp[10001];
int n,sum;

int main(){
  int i,j,maxk = 0;
  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d",&grape[i]);
  }
  dp[1] = grape[1];
  dp[2] = grape[1]+grape[2];

  for(i = 3;i <= n;i++){
    dp[i] =max(dp[i-2],dp[i-3]+grape[i-1])+grape[i];  //grape를 포함한 방법의 비교.
    dp[i] = max(dp[i-1],dp[i]); //grape를 포함하지 않는 것과의 비교.
  }
  printf("%d",dp[n]);
  return 0;
}
