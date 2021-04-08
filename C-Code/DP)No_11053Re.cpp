#include<iostream>
using namespace std;
int arr[1001],dp[1001];
int main(){
  int n,Max = 0;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&arr[i]);
    dp[i] = 1;
  }
  for(int i=2;i<=n;i++){
    for(int j=1;j<i;j++){
      if(arr[j]<arr[i]&&dp[i]<dp[j]+1){
        dp[i] = dp[j]+1;
      }
    }
  }
  for(int i=1;i<=n;i++) Max < dp[i] ? Max = dp[i] : Max = Max;
  printf("%d",Max);
  return 0;
}
