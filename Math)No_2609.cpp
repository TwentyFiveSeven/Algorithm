#include<iostream>
using namespace std;

int main(){
  int a,b,i,j;
  scanf("%d %d",&a,&b);
  int mul = a*b;
  if(a<b){
    i = b;
    b = a;
    a = i;
  }
  if(a%b==0){
    i = b;
    b = 0;
  }
  while(b!=0){
    if(a %b ==0) break;
    i = a % b;
    a = b;
    b = i;
  }
  printf("%d\n",i);
  printf("%d\n",mul/i);
  return 0;
}
