#include<iostream>
using namespace std;

long long n;
long long fibo(long long n){
  if(n == 1 || n == 2)
    return 1;
  else if(n == 0)
    return 0;
  else
    return fibo(n-1)+fibo(n-2);
}

int main(){
  long long value;
  scanf("%lld",&n);
  value = fibo(n);
  printf("%lld",value);
  return 0;
}
