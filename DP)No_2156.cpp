#include<iostream>
#include<algorithm>
using namespace std;
int n,arr[10001][3];
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&arr[i][2]);
  }
  arr[1][0] = arr[1][1] = arr[1][2];
  int Max = arr[1][2];
  for(int i=2;i<=n;i++){
    arr[i][0] = max(arr[i-1][1] + arr[i][2],arr[i-1][0]);
    arr[i][1] = max(arr[i-2][0],arr[i-2][1]) + arr[i][2];
    int value = max(arr[i][0],arr[i][1]);
    if(Max < value) Max = value;
  }
  printf("%d",Max);
  return 0;
}
