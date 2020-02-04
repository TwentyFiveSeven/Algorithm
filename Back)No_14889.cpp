#include<iostream>
#include<math.h>
using namespace std;
int arr[20][20],check[20],sum[2],Min = 1000000001;
int n;

void back(int depth,int start){
  if(depth == n/2){
    sum[0] = 0,sum[1] =0;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(j==i) continue;
        if(check[i] == check[j])
          sum[check[i]] += arr[i][j];
      }
    }
    if(abs(sum[0]-sum[1])<Min)
      Min = abs(sum[0]-sum[1]);
    return;
  }
  for(int i=start;i<n;i++){
    if(depth==0&&i!=0) return;
    if(!check[i]){
      check[i] = 1;
      back(depth+1,i+1);
      check[i] = 0;
    }
  }
}
int main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      scanf("%d",&arr[i][j]);
    }
  }
  back(0,0);
  printf("%d",Min);
  return 0;
}
