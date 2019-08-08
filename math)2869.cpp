#include<iostream>
#include<math.h>
using namespace std;

int main(){
  double A,B,V;
  int i,j,count=1,mul=0;
  scanf("%lf %lf %lf",&A,&B,&V);
  mul = ceil((V-A)/(A-B));
  printf("%d",mul+1);
  return 0;
}
