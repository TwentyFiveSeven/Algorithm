#include<iostream>
using namespace std;

long long check(long long n){
  if(n == 1)
    return 1;
  else if( n== 0){
    return 1;
  }
  else
    return n*check(n-1);
}

int main(){
  long long value,n;
  scanf("%lld",&n);
  value = check(n);
  printf("%lld",value);
  return 0;
}
