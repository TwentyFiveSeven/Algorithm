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
  scanf("%d %d",&a,&b);
  for(int i=a;i<=b;i++){
    if(i == 1)
      continue;
    if(prime(i)){
      sum += i;
      if(check == 0)
        check = i;
    }
  }
  if(sum == 0)
    printf("-1");
  else
    printf("%d\n%d",sum,check);
  return 0;
}
