#include<iostream>
using namespace std;
int arr[500],dp[501],n,Max;
int main(){
  scanf("%d",&n);
  scanf("%d",&arr[0]);
  dp[1] = arr[0];
  for(int i=1;i<n;i++){
    for(int j=i;j>=0;j--){
      scanf("%d",&arr[j]);
      dp[j+1] = max(arr[j]+dp[j+1],arr[j]+dp[j]);
    }
  }
  for(int i=1;i<=n;i++)
    if(dp[i]>Max) Max = dp[i];
  printf("%d",Max);
  return 0;
}
