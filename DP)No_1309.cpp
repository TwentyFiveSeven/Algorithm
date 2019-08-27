#include<iostream>
#include<algorithm>
using namespace std;

int N,arr[100001];

int main(){
  int i,j;
  scanf("%d",&N);
  arr[0] = 1;
  arr[1] = 3;
  for(i=2;i<=N;i++){
    arr[i] = (arr[i-2]+arr[i-1]*2)%9901;
  }
  printf("%d",arr[N]);
  return 0;
}
