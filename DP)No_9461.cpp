#include<iostream>
using namespace std;

long long int dp[101];

int main(){
  int i,j,t=0,n=0,save=3;

  scanf("%d",&t);
  dp[1]=1;dp[2]=1;dp[3]=1;

  while(t--){
    scanf("%d",&n);
    if(save > n){
      printf("%lld\n",dp[n]);
      continue;
    }else{
      for(i=save+1;i<=n;i++){
        dp[i] = dp[i-3]+dp[i-2];
      }
      printf("%lld\n",dp[n]);
    }
    save = n;
  }
  return 0;
}
