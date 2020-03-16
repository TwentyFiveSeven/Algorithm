#include<iostream>
#include<algorithm>
using namespace std;
int dp[501][501],arr[501];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T,K;
  cin>>T;
  while(T--){
    cin>>K;
    for(int i=1;i<=K;i++){
      cin>>arr[i];
      if(i != 1)
        dp[i-1][i] = arr[i-1]+arr[i];
        // cout<<"dp["<<i-1<<"]["<<i<<"] = "<<dp[i-1][i]<<'\n';
    }
    for(int i=K;i>=1;i--){
      for(int j=i;j<=K;j++){
        if(i>=j) {
          dp[i][j] = 0;
          continue;
        }
        if(i+1 == j) continue;
        int val = 2000000001;
        int sum = 0;
        for(int p = i; p <j;p++){
          val = min(val,dp[i][p]+dp[p+1][j]);
          sum += arr[p];
        }
        dp[i][j] = val + sum + arr[j];
      }
    }
    cout<<dp[1][K]<<'\n';
    for(int i=K;i>=1;i--){
      for(int j =i;j<=K;j++){
        dp[i][j] = 0;
      }
    }
  }
  return 0;
}
