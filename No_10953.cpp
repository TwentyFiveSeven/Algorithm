#include<iostream>
using namespace std;

int main(){
  int T,a,b;
  char c;
  scanf("%d",&T);
  while(T--){
    scanf("%d%c%d",&a,&c,&b);
    printf("%d\n",a+b);
  }
  return 0;
}
