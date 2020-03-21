#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
vector<int> V[1000001];
int dp[1000001][2];

int dfs(int current,int old,int select){
  int &ans = dp[current][select];
  if(ans != -1) return ans;
  ans = 0;
  if(select) ans =1;
  int size = V[current].size();
  for(int i=0;i<size;i++){
    int next = V[current][i];
    if(old == next) continue;
    if(select){
      ans += min(dfs(next,current,1),dfs(next,current,0));
    }else{
      ans += dfs(next,current,1);
    }
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N,a,b;
  memset(dp,-1,sizeof(dp));
  cin>>N;
  for(int i=0;i<N-1;i++){
    cin>>a>>b;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  int res1 = dfs(1,0,0);
  int res2 = dfs(1,0,1);
  res1 = min(res1,res2);
  cout<<res1;
  return 0;
}
