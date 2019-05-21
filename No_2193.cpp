#include<iostream>
#include<algorithm>
#include<vector>

long long one[91];
long long zero[91];
long long sum;

int main(){
  long long sum=0;
  int n=0,i;

  scanf("%d",&n);
  one[1] = 1;
  zero[1] = 0;
  one[2] = 0;
  zero[2] = 1;
  for(i=3;i<=n;i++){
    one[i]=zero[i-1]; //끝이 1로시작 -> i-1번째의 0으로끝나는것
    zero[i]=zero[i-1]+one[i-1]; // 끝이 0로시작 -> i-1 번쨰의 1로 끝나는 것 + i-1번쨰의 0으로 끝나는 것
  }
  sum = one[n]+zero[n];
  printf("%lld",sum);
  return 0;
}
