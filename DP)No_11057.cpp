#include<iostream>

using namespace std;

int dp[11]; //2차원 배열을 1차원 배열로 풀이. 이전 값들을 참고 해 가면서 다음값을 구한다.

int main(){
  int i,j,n=0,sum=0;

  for(i=0;i<10;i++){
    dp[i] = 1;
  }

  scanf("%d",&n);

  for(i=2;i<=n;i++){
    for(j=9;j>=0;j--){
      dp[j] = dp[j]+dp[j+1];  //현재 값과 다음 값을 더해서 현재값을 구한다.
      dp[j] = dp[j]%10007;
    }
  }
  for(i=0;i<10;i++){  //모든 값을 다 더해서 답을 구한다.
    sum += dp[i];
    sum = sum%10007;
  }
  printf("%d",sum);

  return 0;
}
