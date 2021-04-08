#include<iostream>
#include<algorithm>

using namespace std;

int dp[1001];

int main(){
  int n=0,k=0,i,j,tmp = 0;

  scanf("%d %d", &n, &k);
  dp[0]=1;dp[1]=1;

  for(i=2;i<=n;i++){    //2부터 시작.
    tmp =i/2;
    for(j=tmp;j>=1;j--){  //1부터 i/2까지 가면 앞에 수의 변형으로 뒷 수가 더 증가하기 때문에 i/2부터 1 까지 연산을한다.
      dp[j] = dp[j]+dp[j-1];
      dp[j] %=10007;    // % 10007을 해준다.
    }
    for(j=i;j>tmp;j--){ //절반까지만 구하고 나머지 절반은 앞에 절반을 복붙.
      dp[j] = dp[i-j];
    }
  }
  printf("%d",dp[k]);

  return 0;
}
