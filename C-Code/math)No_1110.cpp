#include<iostream>

using namespace std;

int main(){
  int n,ans=0,left,right,i,j,count=0;
  scanf("%d",&n);
  ans = n;

  while((n!=ans)||(!count)){
  count++;
  left = ans/10;
  right = ans-left*10;
  ans = left+right;
  ans = right*10+ans%10;
  }
  printf("%d",count);
  return 0;
}
