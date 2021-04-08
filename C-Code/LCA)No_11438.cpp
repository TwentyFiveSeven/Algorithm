#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX ((int)log2(100001))
int N,M,depth[100001];
vector<vector<int>> dp(100001,vector<int>(MAX+1));
vector<int> V[100001];

void dfs(int now,int dep){
  int size = V[now].size();
  for(int i=0;i<size;i++){
    int next = V[now][i];
    if(dp[next][0] != 0 || next == 1) continue;
    dp[next][0] = now;
    depth[next] = dep+1;
    dfs(next,dep+1);
  }
}

int LCA(int x,int y){
  printf("in\n");
  if(depth[x]>depth[y]){
    swap(x,y);
  }
  int val = depth[y] - depth[x];
  for(int i= val;i>=0;i--){
    if(depth[y]-depth[x] >=(1<<i)){
      y = dp[y][i];
    }
  }
  if(x ==y) return x;
  for(int i=MAX;i>=0;i--)
    if(dp[x][i] != dp[y][i]){
      x = dp[x][i];
      y = dp[y][i];
    }
  return dp[x][0];
}

int main(){
  int a,b;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>N;
  for(int i=0;i<N-1;i++){
    cin>>a>>b;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  dfs(1,0);
  for(int i=1;i<=MAX;i++){
    for(int j=1;j<=N;j++){
      dp[j][i] = dp[dp[j][i-1]][i-1];
    }
  }
  cin>>M;
  for(int i=0;i<M;i++){
    cin>>a>>b;
    cout<<LCA(a,b)<<'\n';
  }
  return 0;
}
