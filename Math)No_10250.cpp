#include<iostream>
using namespace std;
int main(){
  int t,h,w,n,mul,layer=0;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d %d",&h,&w,&n);
    mul = n/h; //12
    if(n == h*mul)
      mul -=1;
    layer = n - h*mul; //72 - 72
    if(mul+1<10)
      printf("%d0%d\n",layer,mul+1);
    else
      printf("%d%d\n",layer,mul+1);
  }
  return 0;
}
