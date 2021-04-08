#include<iostream>
using namespace std;
int arr[1000001];
int main(){
  int n;
  scanf("%d",&n);
  arr[1] = 1;
  arr[2] = 2;
  for(int i=3;i<=n;i++){
    arr[i] = (arr[i-1]+arr[i-2])%15746;
    // arr[i] = arr[i-1]값들 뒤에 1을 붙이고, arr[i-2]값들 뒤에 00을 붙인 타일들의 합이다.
  }
  printf("%d",arr[n]);
  return 0;
}
