#include<iostream>
using namespace std;
long long arr[91];
int n;
int main(){
  arr[0] = 0;
  arr[1] = 1;
  scanf("%d",&n);
  for(int i = 2;i<=n;i++){
    arr[i] = arr[i-1]+arr[i-2];
  }
  printf("%lld",arr[n]);
  return 0;
}
