#include<iostream>
#include<algorithm>

using namespace std;

int arr[2][100001];
int ans[2][100001];
int main(){
  int t=0,n=0,result = 0,i,j;

  scanf("%d",&t);

  while(t--){
    scanf("%d",&n);

    for(i=0;i<2;i++){
      for(j=1;j<=n;j++){
        scanf("%d",&arr[i][j]);
      }
    }
    ans[0][1] = arr[0][1];
    ans[1][1] = arr[1][1];
    //현재 위치에서 -1번째 대각선, -2번째 대각선 중 큰 값과 연산.(1행, 2행 두가지 경우에 대해 수행)
    for(i=2;i<=n;i++){
      ans[0][i] = max(ans[1][i-2],ans[1][i-1])+arr[0][i];
      ans[1][i] = max(ans[0][i-2],ans[0][i-1])+arr[1][i];
    }
    result = max(ans[1][n],ans[0][n]);
    printf("%d\n",result);
  }
}
