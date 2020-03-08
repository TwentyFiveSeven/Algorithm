#include<iostream>
using namespace std;
int n,k;

int main(){
  scanf("%d %d",&n,&k);
  int left = 1, right = k,ans=0;
  while(left<=right){
    int mid = (left+right)/2;
    int count = 0;
    for(int i=1;i<=n;i++) count += min(mid/i,n);
    if(count >= k) {
      right = mid-1;
      ans = mid;
    }else{
      left = mid+1;
    }
  }
  printf("%d",ans);
  return 0;
}
