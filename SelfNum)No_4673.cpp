#include<iostream>
using namespace std;

int arr[10001] ={0,};

void sum(int n){
  int ret = n;
  while(n>0){
    ret += n%10;
    n /=10;
  }
  if(arr[ret] == 1 || ret>10000)
    return;

  arr[ret] = 1;
  sum(ret);
}

int main(){
  int i,value=0;
  for(i=1;i<=10000;i++){
    if(arr[i] ==0){
      sum(i);
    }
  }
  for(i=1;i<=10000;i++){
    if(arr[i] ==0)
      printf("%d\n",i);
  }
  return 0;
}
