#include<iostream>
#define MOD 1000000007
using namespace std;

int dp[301][301];

int main(){
  int h,w;
  cin >> h >> w;
  dp[1][1] = 1;
  for(int i=2;i<=300;i++){
    dp[1][i] = 1;
  }
  for(int i=2; i<=h;i++){
    for(int j=i; j<=w;j++){
      int dp_value = 0;
      for(int k=0;k<=i-1;k++){
        for(int m=k; m<=j-1;m++){
          dp_value += dp[i-k][m] * dp[k][j-m];
          cout<<i-k<<' '<<m<<' '<<k<<' '<<j-m<<' '<<dp_value<<'\n';
        }
      }
      dp[i][j] = dp_value;
    }
  }
  cout<<dp[h][w];
  return 0;
}
