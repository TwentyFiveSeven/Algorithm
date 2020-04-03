#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
#define MAX ((int)log2(100001))
vector<pair<int,int>> V[100001];
vector<int> K(2,0);
int check[100001],depth[100001],Min[100001][MAX+1],Max[100001][MAX+1],dp[100001][MAX+1];

void dfs(int now, int dep){
  int size = V[now].size();
  check[now] = 1;
  for(int i=0;i<size;i++){
    int next = V[now][i].first;
    if(check[next] == 1) continue;
    Min[next][0] = V[now][i].second;
    Max[next][0] = V[now][i].second;
    dp[next][0] = now;
    depth[next] = dep +1;
    dfs(next,dep+1);
  }

}

int LCA(int a, int b){
  K[0] = -2100000001, K[1] = 2100000001;
  if(depth[a] > depth[b]) //항상 b가 depth 크다
    swap(a,b);
  for(int i=MAX;i>=0;i--){
    if(depth[b]-depth[a]>=(1<<i)){
      K[0] = max(K[0],Max[b][i]);
      K[1] = min(K[1],Min[b][i]);
      b = dp[b][i];
    }
  }
  if(a == b) return 0;
  for(int i=MAX;i>=0;i--){
    if(dp[a][i] != dp[b][i]){
      K[0] = max({K[0],Max[a][i],Max[b][i]});
      K[1] = min({K[1],Min[a][i],Min[b][i]});
      a = dp[a][i];
      b = dp[b][i];
    }
  }
  K[0] = max({K[0],Max[a][0],Max[b][0]});
  K[1] = min({K[1],Min[a][0],Min[b][0]});
  return 0;
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
      Min[j][i] = min(Min[j][i-1],Min[dp[j][i-1]][i-1]);
      Max[j][i] = max(Max[j][i-1],Max[dp[j][i-1]][i-1]);
    }
  }
  cin>>M;
  for(int i=0;i<M;i++){
    cin>>a>>b;
    LCA(a,b);
    cout<<K[1]<<' '<<K[0]<<'\n';
  }
  return 0;
}
