#include<iostream>
using namespace std;
int arr[1500001];
/* 피사노 주기 구하는 함수
long long pisano_period(long long m){
  int f0 = 0, f1 = 1, f2 = 1;
  for(int i=0;i<m*m;i++) 주기<m*m 을 사용
  {
    f2 = (f0+f1)%m;
    f0 = f1;
    f1 = f2;
    if(f0 ==0 && f1 == 1) return i+1;
    // 0과 1 의 반복을 통해서 주기를 찾는다.
  }
}
*/
int main(){
  long long n;
  scanf("%lld",&n);
  n %= 1500000;
  arr[1]=arr[2] = 1;
  for(int i=3;i<=n;i++){
    arr[i] = (arr[i-1]+arr[i-2])%1000000;
  }
  printf("%d",arr[n]);
  return 0;
}
