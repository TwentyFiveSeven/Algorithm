#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int arr[50001],dp[50000];
int main(){
  int input;
  scanf("%d",&input);
  dp[1] = 1; dp[2] = 2;dp[3] = 3;dp[4] = 1;
  for(int i=5;i<=input;i++){
    dp[i] = i;
    int temp = sqrt(i);
    int test = temp*temp;
    if(test == i) {
      dp[i] = 1;
      continue;
    }
    for(int j=temp;j>=temp/2;j--){
      int save = dp[i];
      dp[i] = min(dp[i],dp[j*j]+dp[i-j*j]);
    }
  }
  printf("%d",dp[input]);
  return 0;
}
