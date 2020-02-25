#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> V;
int dp[101];
int main(){
  int n,tmp1,tmp2,Max = 0,VMax = 0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d %d",&tmp1,&tmp2);
    V.push_back(make_pair(tmp1,tmp2));
    dp[i] = 1;
  }
  sort(V.begin(),V.end());

  for(int i=1;i<n;i++){
    for(int j = 0; j<i;j++){
      if(V[j].second<V[i].second&&dp[i]<dp[j]+1){
        dp[i] = dp[j]+1;
        if(dp[i] > VMax) VMax = dp[i];
      }
    }
  }
  printf("%d",n-VMax);
  return 0;
}
