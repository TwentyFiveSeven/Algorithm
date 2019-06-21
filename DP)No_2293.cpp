#include<iostream>

using namespace std;

int arr[101];
int dp[10001];

int main(){
  int n=0,k=0,i,j,tmp=0;

  scanf("%d %d",&n, &k);

  for(i=1;i<=n;i++){
    scanf("%d", &arr[i]);
  }

  dp[0] = 1;
  for(i=1;i<=n;i++){
    for(j=1;j<=k;j++){
      if(j>=arr[i]){
        tmp = j - arr[i];
        dp[j] += dp[tmp];
      }
    }
  }
  printf("%d\n",dp[k]);
  return 0;
}
