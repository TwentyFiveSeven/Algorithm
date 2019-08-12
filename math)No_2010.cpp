#include<iostream>

using namespace std;

int main(){
  int sum=0,input = 0,n,i;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&input);
    sum += input-1;
  }
  printf("%d",sum+1);
  return 0;
}
