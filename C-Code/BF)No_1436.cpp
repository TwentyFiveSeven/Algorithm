#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
  int n,count = 0, i = 666;
  scanf("%d",&n);
  while(1){
    int value = i;
    while(value >0){
      if(value%1000 == 666){
        count++;
        break;
      }
      value = value/10;
    }
    if(n == count){
      break;
    }
    i++;
  }
  printf("%d",i);
  return 0;
}
