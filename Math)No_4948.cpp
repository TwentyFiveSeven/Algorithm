#include<iostream>
#include<math.h>
using namespace std;

int prime(int num){
  for(int i=2;i<=sqrt(num);i++){
    if(num%i==0)
      return 0;
  }
  return 1;
}

int main(){
  int a,b,i,check=0,sum=0;
  while(1){
    scanf("%d",&a);
    if(a == 0)
      break;
    int count = 0;
    b = a*2;
    for(int i=a+1;i<=b&&i>0;i++){
      if(i == 1)
        continue;
      if(prime(i)){
        count++;
      }
    }
    printf("%d\n",count);
  }
}
