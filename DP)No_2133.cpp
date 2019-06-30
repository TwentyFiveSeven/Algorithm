#include<iostream>
#include<math.h>
using namespace std;

long long int dp[31];
int casenum[31];

int main(){
  int n=0,i,j;

  scanf("%d",&n);

  if(n%2){
    printf("0");
    return 0;
  }
  fill_n(casenum,31,2);
  casenum[2]=3;dp[0]=1;

  for(i=2;i<=n;i=(i+2)){
    for(j=2;j<=i;j=(j+2)){
      dp[i] += dp[i-j]*casenum[j];  // 만약 n = 6일 경우, (6-2)*2, (6-4)*4, (6-6)*6 의 경우의 수를 구해야하고, 좌측에 있는 경수의 수 (6-2)일경우 구할 수 있는
    }                               // 모든 경우의 수 ex)4 -> 2*2, 4 = 11 의 값이고, 우측 경우의 수는 4개가 독릭적으로 갖을 수 있는 경우의 수 2 이다.
  }

  printf("%lld",dp[n]);
  return 0;
}
