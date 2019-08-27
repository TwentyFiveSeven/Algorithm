#include<iostream>
using namespace std;

int arr[1000],dp[1000],N;

int main(){
  int i,j,max,ans=0;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&arr[i]);

  for(i=0;i<N;i++){
    max = 0;
    for(j=0;j<=i;j++){
      if(arr[i]>arr[j]&&dp[j]>max){
        dp[i] = dp[j]+1;
        max = dp[j];
      }
      if(!dp[i]) dp[i] =1;
      if(dp[i]>ans) ans = dp[i];
    }
  }
  printf("%d",ans);
  return 0;
}
