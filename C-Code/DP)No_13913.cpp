#include<iostream>
#include<queue>
#include<vector>
#include<string.h>
using namespace std;
typedef struct{
  int x,y,z;
}Struc;
struct cmp{
  bool operator()(Struc a ,Struc b){
    return a.x>b.x;
  }
};
int dp[100001],rmb[100001];
int N,K;
priority_queue<Struc,vector<Struc>,cmp> pq;

void bfs(int start, int End){
  int minus,plus,mul;
  pq.push({0,start,-1});
  while(!pq.empty()){
    int count = pq.top().x;
    start = pq.top().y;
    int save = pq.top().z;
    pq.pop();
    if(dp[start] != -1) continue;
    dp[start] = count;
    rmb[start] = save;
    if(start == K) break;
    if(start*2>=0 && start*2<=100000 && dp[start*2] == -1)
      pq.push({count+1,start*2,start});
    if(start+1>=0 && start+1<=100000 && dp[start+1] == -1)
      pq.push({count+1,start+1,start});
    if(start-1>=0 && start-1<=100000 && dp[start-1] == -1)
      pq.push({count+1,start-1,start});
  }
  printf("%d\n",dp[K]);
  int p = K;
  vector<int> V;
  while( p != -1){
    V.push_back(p);
    p = rmb[p];
  }
  int size = V.size();
  for(int i=size-1;i>=0;i--){
    printf("%d ",V[i]);
  }
}

int main(){
  int count = 0;
  memset(dp,-1,sizeof(dp));
  scanf("%d %d",&N,&K);
  bfs(N,K);
  return 0;
}
