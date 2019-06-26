#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001][1001];

int main(){
  int n=0,m=0,i,j,tmp=0;

  scanf("%d %d",&n,&m);

  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){                                     //순차적으로 계산해 나가면서 현재 위치에서 최대가 되기위해 현재 위치로 올 수 있는 곳들 중
      scanf("%d", &arr[i][j]);                            //가장 큰 곳을 골라서 현재 위치의 사탕 수와 더해준다.
      tmp = max(arr[i-1][j-1],arr[i-1][j]);               //구하려는 수의 대각선과, 위쪽중 큰 것을 선택.
      arr[i][j] = max(arr[i][j-1],tmp) + arr[i][j];      // 위에서 선택한 것과 왼쪽에있는 값 중 큰 값을 선택하여 현재 사탕 수와 더한다.
    }
  }
  printf("%d",arr[n][m]);

  return 0;
}
