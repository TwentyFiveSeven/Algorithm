#include<iostream>
#include<algorithm>
using namespace std;
int arr[100001],dp[100001],save=0,first=0;
int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  dp[0] = arr[0];
  first = 0;
  for(int i=1;i<n;i++){
    dp[i] = max({dp[i-1],first+arr[i]});

    if(arr[i]<0) first = 0;
    else first += arr[i];
    printf("dp[i-1] : %d, first+arr[i] : %d, first : %d, dp[i] : %d\n",dp[i-1],first+arr[i],first,dp[i]);
  }
  for(int i=0;i<n;i++){
    printf("%d ",dp[i]);
  }
  return 0;
}
