#include<iostream>
#include<vector>
using namespace std;

vector<int> V[100001];
int countC[100001];

void dfs(int current){
  int size = V[current].size();
  countC[current] = 1;
  for(int i=0;i<size;i++){
    if(countC[V[current][i]] != 0)continue;
    dfs(V[current][i]);
    countC[current] += countC[V[current][i]];
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N,R,Q,x,y;
  cin>>N>>R>>Q;
  for(int i=0;i<N-1;i++){
    cin>>x>>y;
    V[x].push_back(y);
    V[y].push_back(x);
  }
  dfs(R);
  for(int i=0;i<Q;i++){
    cin>>x;
    cout<<countC[x]<<'\n';
  }
  return 0;
}
