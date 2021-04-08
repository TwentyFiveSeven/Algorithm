#include<iostream>
using namespace std;
int arr[1002];
int main(){
  int n,k;
  scanf("%d %d",&n,&k);
  arr[1] = arr[2] = 1;
  for(int i=2;i<=n;i++){
    for(int j=i+1;j>=1;j--){
      arr[j] = (arr[j]+arr[j-1])%10007;
    }
  }
  printf("%d",arr[k+1]);
  return 0;
}
