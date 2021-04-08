#include<iostream>

using namespace std;

int arr[101];
int dp[10001];

int main(){
  int n=0,k=0,i,j,tmp=0;

  scanf("%d %d",&n, &k);

  for(i=1;i<=n;i++){
    scanf("%d", &arr[i]);
  }

  dp[0] = 1;
  for(i=1;i<=n;i++){    //이 문제는 동전의 가짓수를 추가 하면서 k 에서만 확인하는 것이 아니라
    for(j=1;j<=k;j++){  // 동전의 수를 늘려갈 때 마다 0~k까지의 모든 수의 경우의 수를 확인해줘야한다.
      if(j>=arr[i]){  // 현재 사용가능한 동전보다 작은 값을 구할 때는 전의 경우와 같은 값을 return, 큰 값을 구 할 때는
        tmp = j - arr[i]; //이전 동전상황의 경우의 수 + 현재 수로 k를 표현하는 방법 을 구해준다.
        dp[j] += dp[tmp];
      }
    }
  }
  printf("%d\n",dp[k]);
  return 0;
}
