#include<iostream>
using namespace std;

int mul(int a,int b,int c){
  if(b == 0) return 1;
  int temp = mul(a,b/2,c) % c;
  int ret = (1LL * temp *temp) % c;
  if(b%2) ret = 1LL * ret *a%c;
  return ret;
}

int main(){
  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  int ret = mul(a,b,c);
  printf("%d",ret);
  return 0;
}
