#include<iostream>
using namespace std;
int arr[41][2];
int main(){
  arr[0][0] = 1;
  arr[1][1] = 1;
  int n,t,save = 2;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    if(n<save){
      printf("%d %d\n",arr[n][0],arr[n][1]);
      continue;
    }
    for(int i= save;i<=n;i++){
      arr[i][0] = arr[i-1][0] + arr[i-2][0];
      arr[i][1] = arr[i-1][1] + arr[i-2][1];
    }
    printf("%d %d\n",arr[n][0],arr[n][1]);
    save = n;
  }
  return 0;
}
