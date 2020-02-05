#include<iostream>
using namespace std;
long long arr[101];
int main(){
  int t,n,save = 4;
  scanf("%d",&t);
  arr[1] = 1; arr[2] = 1;arr[3] =1;
  while(t--){
    scanf("%d",&n);
    if(n<save){
      printf("%lld\n",arr[n]);
      continue;
    }
    for(int i=save;i<=n;i++){
      arr[i] = arr[i-2]+arr[i-3];
    }
    printf("%lld\n",arr[n]);
    save = n;
  }
  return 0;
}
