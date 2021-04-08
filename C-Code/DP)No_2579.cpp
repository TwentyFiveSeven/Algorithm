#include<iostream>
using namespace std;
int arr[301][3],n;
int main(){
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&arr[i][2]);
  }
  arr[1][0] = arr[1][1] = arr[1][2];
  for(int i=2;i<=n;i++){
    arr[i][0] = arr[i-1][1]+arr[i][2];
    arr[i][1] = max(arr[i-2][0],arr[i-2][1]) + arr[i][2];
  }
  printf("%d",max(arr[n][0],arr[n][1]));
  return 0;
}
