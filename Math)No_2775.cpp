#include<iostream>
using namespace std;

int arr[15];
int main(){
  int t,k,n,i;
  for(int i=1;i<=14;i++){
    arr[i] = i;
  }
  scanf("%d",&t);
  while(t--){
    scanf("%d",&k);
    scanf("%d",&n);
    while(k--){
      for(int i=1;i<=n;i++){
        arr[i] = arr[i-1]+ arr[i];
      }
    }
    printf("%d\n",arr[n]);
    for(int i=1;i<=n;i++)arr[i] = i;
  }
  return 0;
}
