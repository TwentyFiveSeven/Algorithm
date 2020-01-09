#include <iostream>
using namespace std;

void hanoi(int n,int a,int b){
int c;
  if(n<=1){
    printf("%d %d\n",a,b);
  }else{
    c = 6 - a - b;
    hanoi(n-1,a,c);
    printf("%d %d\n",a,b);
    hanoi(n-1,c,b);
  }
}

int main(){
  int n,k;
  long long mul = 2;
  scanf("%d",&n);
  k = n-1;
  while(k--) mul *=2;
  printf("%lld\n",mul-1);
  hanoi(n,1,3);
  return 0;
}
