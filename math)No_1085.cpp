#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int a,b,c,d,i,ans=0;
  scanf("%d %d %d %d",&a,&b,&c,&d);
  ans = min({c-a,d-b,a,b});
  printf("%d",ans);
  return 0;
}
