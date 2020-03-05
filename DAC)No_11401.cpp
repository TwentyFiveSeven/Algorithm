#include<iostream>
#define P 1000000007LL
using namespace std;
long long arr[4000001],inv[4000001];

//페르마의 소정리 fac 의  P-2제곱을 구하기.
// N! * (N-K)!^(P-2) * K!^(P-2) % P 구하기.
int Pow(long long val,long long p){
  long long ret = 1;
  while(p>0){
    if(p%2){
      ret *=val;
      ret %= P;
    }
    val *= val;
    val %= P;
    p /= 2;
  }
  return ret;
}

int main(){
  int n,k;
  arr[1] = 1;
  scanf("%d %d",&n,&k);
  if(n == k || !k){
    printf("1");
    return 0;
  }
  for(int i=2;i<=n;i++){
    arr[i] = (arr[i-1]*i)%P;
  }
  inv[n] = Pow(arr[n],P-2);
  for(int i=n-1;i>=0;i--){
    inv[i] = inv[i+1]*(i+1)%P;
  }
  long long ret = arr[n]*inv[n-k]%P;
  ret = ret*inv[k]%P;
  printf("%lld",ret);
  return 0;
}
