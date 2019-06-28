#include<iostream>

using namespace std;

long long int dp[31];

int main(){
  int n=0,i,j;

  scanf("%d",&n);

  dp[1] = 0;
  dp[2] = 3;
  dp[3]= 0;
  if(!(n%2)){
    for(i=4;i<=n;i++){
      if(!(i%2)){
        dp[i] = dp[i-2]*3+2;
      }
    }
    printf("%lld",dp[n]);
  }else{
    printf("0");
  }

  return 0;
}
