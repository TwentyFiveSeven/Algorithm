#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001],n;
int main(){
  int i,j,sum=0,ans=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&arr[i]);
  }
  sort(arr+1,arr+n+1);
  for(i=1;i<=n;i++){
    sum = sum + arr[i];
    ans += sum;
  }
  printf("%d",ans);

  return 0;
}
