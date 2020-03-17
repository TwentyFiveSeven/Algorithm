#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> V;
int N,arr[1000][3],dp[1000][3];
int main(){
  int ret=1000001;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
  }
  dp[0][0] = arr[0][0];
  dp[0][1] = arr[0][1];
  dp[0][2] = arr[0][2];
  for(int i=0;i<3;i++){
    int tmp = dp[0][i];
    dp[0][i] = 1000001;
    for(int j=1;j<N;j++){
      dp[j][0] = min(dp[j-1][1]+arr[j][0],dp[j-1][2]+arr[j][0]);
      dp[j][1] = min(dp[j-1][0]+arr[j][1],dp[j-1][2]+arr[j][1]);
      dp[j][2] = min(dp[j-1][0]+arr[j][2],dp[j-1][1]+arr[j][2]);
    }
    dp[0][i] = tmp;
    ret = min(ret,dp[N-1][i]);
  }
  printf("%d",ret);
  return 0;
}
