#include<iostream>
using namespace std;
int dp[101];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T,N;
  cin>>T;
  dp[1] = 1;
  for(int i=2;i<=100;i++){
    int val = dp[i-1]+1;
    if(val*val > i)
      dp[i] = dp[i-1];
    else
      dp[i] = dp[i-1]+1;
  }
  while(T--){
    cin>>N;
    cout<<dp[N]<<'\n';
  }
  return 0;
}
