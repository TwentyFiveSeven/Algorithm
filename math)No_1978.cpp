#include<iostream>
#include<math.h>
using namespace std;
int main(){
  int i,j,n,ans,count;
  scanf("%d",&n);
  count = n;
  for(i=1;i<=n;i++){
    scanf("%d",&ans);
    if(ans ==1) count--;
    for(j=2;j<=sqrt(ans);j++){
      if(ans%j==0){
        count--;
        break;
      }
    }
  }
  printf("%d",count);
  return 0;
}
