#include<iostream>
#include<math.h>

using namespace std;
int arr[1000001]; //계속 규칙을 찾아보니 피보나치수열이었다...
int main(){
  int i,j;
  int n, value;
  scanf("%d",&n);
  arr[0]=1;
  arr[1]=1;
  for(i=2;i<=n;i++){
    arr[i] = (arr[i-2]+arr[i-1])%15746;
  }
  printf("%d",arr[n]);
  return 0;
}
