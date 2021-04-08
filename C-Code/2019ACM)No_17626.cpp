#include<iostream>
#include<math.h>
using namespace std;

int dp[50001];

int main(){
  dp[0] = dp[1] =1;
  int n;
  cin>>n;
  for(int i=2;i<=n;i++){
    int sqrtNum = sqrt(i);
    if(sqrtNum * sqrtNum == i){
      dp[i] = 1;
      continue;
   }
    dp[i] = 100;
    for(int j = sqrtNum; j>=1;j--){
      dp[i] = min(dp[i], dp[j*j]+dp[i-j*j]);
    }
  }
  cout<<dp[n];
}
