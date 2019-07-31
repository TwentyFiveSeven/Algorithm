#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int weight[10001],dp[10001],n,arr[10001][3],maxN;

int bfs(){
  int i;
  for(i=1;i<=n;i++){
    dp[i] = max({arr[i][1]+arr[i][2],dp[i]+arr[i][1],dp[i]+arr[i][2]});
    dp[arr[i][1]] = dp[i];
    dp[arr[i][2]] = dp[i];
    printf("dp[%d], dp[%d], dp[%d] : %d\n",i,arr[i][1],arr[i][2],dp[i]);
    if(dp[i]>maxN) maxN = dp[i];
  }
}

int main(){
  int i,j,parent=0,child=0,Nweight=0;
  scanf("%d",&n);
  for(i=1;i<n;i++){
    scanf("%d %d %d",&parent,&child,&Nweight);
    if(arr[parent][1]==0){
       arr[parent][1] = child;
       weight[child] = Nweight;
       continue;
     }
     arr[parent][2] = child;
     weight[child] = Nweight;
  }
  // for(i=1;i<=n;i++){
  //   printf("root : %d, left : %d, right : %d\n",i,arr[i][1],arr[i][2]);
  // }
  bfs();
  printf("%d",maxN);
}
