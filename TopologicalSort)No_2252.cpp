#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int count[32001],N,M;
vector<int> V[32001],ans;
queue<int> Q;

void Sort(){
  while(!Q.empty()){
    int val = Q.front();
    Q.pop();
    ans.push_back(val);
    int size = V[val].size();
    for(int i=0;i<size;i++){
      int next = V[val][i];
      count[next]--;
      if(count[next] == 0)
        Q.push(next);
    }
  }
}
int main(){
  int a,b;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>N>>M;
  for(int i=0;i<M;i++){
    cin>>a>>b;
    V[a].push_back(b);
    count[b]++;
  }
  for(int i=1;i<=N;i++){
    if(count[i] == 0)
      Q.push(i);
  }
  Sort();
  int size = ans.size();
  for(int i=0;i<size;i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}
