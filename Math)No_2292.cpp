#include<iostream>
using namespace std;

int main(){
  int n,i,ans=1,sum=1;
  scanf("%d",&n);
  while(n>sum){
    sum += 6*ans;
    ans++;
  }
  printf("%d",ans);
  return 0;
}
