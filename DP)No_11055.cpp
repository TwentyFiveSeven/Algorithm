#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001],dp[1001],n;  //dp와 함께 진행하면서 최대값을 기억해주는게 중요하다.
int main(){
  int i,j,value=0;
  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d",&arr[i]);
    dp[i] = arr[i]; //dp의 최초값도 시작 배열과 같다.
  }
  value = arr[1];
  for(i=1;i<=n;i++){  // 비교 시작점.
    for(j=i;j<=n;j++){  //더하기 위한 두번째 비교
      if(arr[j]>arr[i]){ //만약 비교하는 숫자가 비교의 시작점보다 크다면
        dp[j] = max(dp[j],dp[i]+arr[j]); //같은 j의 값이 계속 계산 되기 떄문에dp[j]와 dp[i]+arr[j]중에 큰값을 고른다.
        if(dp[j]>value) value = dp[j];  //최대값 저장.
      }
    }
  }
  printf("%d",value);
  return 0;
}
