#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
#define MAX ((int)log2(100001))
vector<pair<int,int>> V[100001];
int check[100001],depth[100001],dp[100001][MAX+1];
long long Value[100001][MAX+1];

void dfs(int now, int dep){
  int size = V[now].size();
  check[now] = 1;
  for(int i=0;i<size;i++){
    int next = V[now][i].first;
    if(check[next] == 1) continue;
    Value[next][0] = V[now][i].second;
    dp[next][0] = now;
    depth[next] = dep +1;
    dfs(next,dep+1);
  }

}

long long LCA(int a, int b){
  long long val = 0;
  if(depth[a] > depth[b]) //항상 b가 depth 크다
    swap(a,b);
  // int val = depth[b]-depth[a];
  for(int i=MAX;i>=0;i--){
    if(depth[b]-depth[a]>=(1<<i)){
      val += Value[b][i];
      b = dp[b][i];
    }
  }
  if(a == b) return val;
  for(int i=MAX;i>=0;i--){
    if(dp[a][i] != dp[b][i]){
      val += Value[b][i]+Value[a][i];
      a = dp[a][i];
      b = dp[b][i];
    }
  }
  val += Value[b][0]+Value[a][0];
  return val;
}

int LCA2(int x,int y){
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

int FIND(int a, int b, int c){
  int parent = LCA2(a,b);
  if(c == depth[a]-depth[parent]+1) return parent;
  else{
    if(c-1<depth[a]-depth[parent]){
      int dep = depth[a] - (c-1);
      for(int i=MAX;i>=0;i--){
        if(depth[a]-dep>=(1<<i)){
          a = dp[a][i];
        }
      }
      return a;
    }else{
      int dep = (c-1)-depth[a]+2*depth[parent];
      for(int i=MAX;i>=0;i--){
        if(depth[b]-dep>=(1<<i)){
          b = dp[b][i];
        }
      }
      return b;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N,a,b,val,M;
  cin>>N;
  for(int i=0;i<N-1;i++){
    cin>>a>>b>>val;
    V[a].push_back(make_pair(b,val));
    V[b].push_back(make_pair(a,val));
  }
  dfs(1,0);
  for(int i=1;i<=MAX;i++){
    for(int j=1;j<=N;j++){
      dp[j][i] = dp[dp[j][i-1]][i-1];
      Value[j][i] = Value[j][i-1] + Value[dp[j][i-1]][i-1];
    }
  }
  int c,d;
  cin>>M;
  for(int i=0;i<M;i++){
    cin>>a;
    if(a == 1){
      cin>>b>>c;
      cout<<LCA(b,c)<<'\n';
    }else{
      cin>>b>>c>>d;
      cout<<FIND(b,c,d)<<'\n';
    }
  }
  return 0;
}
