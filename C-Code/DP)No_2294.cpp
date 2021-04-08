#include<iostream>
#include<algorithm>

using namespace std;

int arr[101];
int dp[101][10001];

int main(){
  int i,j,n=0,k=0,tmp=0

  scanf("%d %d",&n,&k);

  for(i=1;i<=n;i++)
    scanf("%d",&arr[i]);

  for(i=0;i<=k;i++){
    dp[0][i] = 10001;
  }
  for(i=1;i<=n;i++){
    dp[i][0] = 10001;
    for(j=1;j<=k;j++){
      if(j>=arr[i]){
        tmp = j-arr[i];
        if(j%arr[i]==0){                            //현재 구하는 값이 arr[i]에 나누어 떨어지면 나눈 값과( j/arr[i] )
          dp[i][j] = min(dp[i-1][j],j/arr[i]);      //i번째 까지의 값으로 구한 값( dp[j-arr[i]]+1 ),
          dp[i][j] = min(dp[i][tmp]+1,dp[i][j]);    //그리고 i-1번째 까지의 값( dp[i-1][j] )으로 구한 값을 비교.
        }else{
            dp[i][j] = min(dp[i-1][j],dp[i][tmp]+1);  //나누어 떨어지지않으면 i-1번째 까지의 값으로 구한 값( dp[i-1][j] )과
        }                                             //i번째 까지의 값으로 구한 값( dp[i][j-arr[i]]+1 )을 비교.
      }else{
        dp[i][j] = dp[i-1][j];     // 현재 i번째 수보다 값이 작을 때는 위에 구했던 경우를 그대로 가져온다.
      }
    }
  }
  
  if(dp[n][k] == 10001)
    printf("-1");
  else
    printf("%d",dp[n][k]);
  return 0;
}
