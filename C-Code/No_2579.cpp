#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int stair[301];
int dp[301][301];
int n,ans;

int main(){
  int i,j;
  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d",&stair[i]);
    dp[i][i]=stair[i];
  }
  dp[2][1]=dp[1][1]+dp[2][2];
  dp[3][2]=dp[2][2]+dp[3][3];
  dp[3][1]=dp[1][1]+dp[3][3];

  for(i=4;i<=n;i++){
    for(j=i-2;j<i;j++){
      dp[i][j]=dp[j][j-2]+dp[i][i];
      if(j==i-2){
        dp[i][j]=max(dp[j][j-1]+dp[i][i],dp[j][j-2]+dp[i][i]);
      }
    }
  }
  ans = max(dp[n][n-1],dp[n][n-2]);
  printf("%d",ans);

  return 0;
}
