#include<iostream>
using namespace std;
int arr[1000],dp[1000],dp1[1000];
int main(){
  int n,Max=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    dp[i] = dp1[i] = 1;
  }
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(arr[i]>arr[j]&&dp[i]<dp[j]+1){
        dp[i] = dp[j]+1;
      }
    }
  }
  for(int i=n-2;i>=0;i--){
    for(int j=n-1;j>i;j--){
      if(arr[i]>arr[j]&&dp1[i]<dp1[j]+1){
        dp1[i] = dp1[j]+1;
      }
    }
  }
  for(int i=0;i<n;i++) {
    Max < dp[i]+dp1[i] ? Max = dp[i]+dp1[i] : Max = Max;
  }
  printf("%d",Max-1);
}
