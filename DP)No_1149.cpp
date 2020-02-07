#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001][3],dp[3];
int n;
int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d %d %d",&arr[i][0],&arr[i][1],&arr[i][2]);
  }
  dp[0] = arr[0][0];dp[1] = arr[0][1];dp[2] = arr[0][2];
  for(int i=1;i<=n;i++){
    int tmp0 = min(arr[i][0]+dp[1],arr[i][0]+dp[2]);
    int tmp1 = min(arr[i][1]+dp[0],arr[i][1]+dp[2]);
    int tmp2 = min(arr[i][2]+dp[0],arr[i][2]+dp[1]);
    dp[0] = tmp0; dp[1] = tmp1; dp[2] = tmp2;
  }
  printf("%d",min({dp[0],dp[1],dp[2]}));
  return 0;
}
