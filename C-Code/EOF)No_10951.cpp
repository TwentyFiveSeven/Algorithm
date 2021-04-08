#include <iostream>

using namespace std;

int main(){
  int a,b;
  while(scanf("%d %d",&a,&b)!=EOF){
    if(!a && !b) break;
    printf("%d\n",a+b);
  }
  return 0;
}
