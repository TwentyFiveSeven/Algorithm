#include<iostream>
#include<algorithm>
using namespace std;
long long int arr[51];
int main(){
  int n,i,j;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&arr[i]);
  }
  sort(arr+1,arr+n+1);
  printf("%lld",arr[1]*arr[n]);
  return 0;
}
