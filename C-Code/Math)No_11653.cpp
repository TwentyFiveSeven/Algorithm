#include<iostream>
using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  for(int i=2;i<=n;i++){
    if(n<i|| n == 0) break;
    while(n % i == 0){
      printf("%d\n",i);
      n /=i;
    }
  }
  return 0;
}
