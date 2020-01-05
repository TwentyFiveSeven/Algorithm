#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int a,b;
  scanf("%d %d",&a,&b);
  b = b-45;
  if(b <0){
    b = 60 - abs(b);
    a -=1;
    if(a<0)
      a = 23;
  }
  printf("%d %d",a,b);
  return 0;
}
