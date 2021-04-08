#include<iostream>
using namespace std;
int arr[201],dp[201];
int main(){
  int N,i;
  cin>>N;
  for(i=1;i<=N;i++){
    cin>>arr[i];
    dp[i] = 1;
  }
  for(i=1;i<=N;i++){
    int Max = 0;
    for(int j=1;j<i;j++){
      if(arr[i]>arr[j] && dp[j]>=Max){
        Max = dp[j]+1;
        dp[i] = dp[j]+1;
      }
    }
  }
  int Max = 0;
  for(int j=1;j<=N;j++){
    Max = max(Max,dp[j]);
  }
  cout<<N-Max;
  return 0;
}
