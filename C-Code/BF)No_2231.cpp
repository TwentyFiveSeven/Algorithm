#include <iostream>
using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  for(int i=n/2;i<n;i++){
    int t = i,sum = t;
    while(t>0){
      sum += t%10;
      t /= 10;
    }
    if(sum == n){
      printf("%d",i);
      return 0;
    }
  }
  printf("0");
  return 0;
}
