#include<iostream>
#include<cstdio>
// #include<queue>
// #include<vector>
using namespace std;
int arr[500][500],N,M,dp[500][500];
// queue<pair<int,int>> Q;
// vector<pair<int,int>> V;
int xi[4] = {0,0,1,-1};
int yi[4] = {1,-1,0,0};
int DFS(int x,int y){
  if(x == 0 && y ==0) return 1;
  if(dp[x][y] != -1) return dp[x][y];
  int ret = 0;
  for(int i=0;i<4;i++){
    int nx = x+xi[i];
    int ny = y+yi[i];
    if(nx>=0&&nx<N&&ny>=0&&ny<M)
      if(arr[nx][ny]>arr[x][y]){
        ret += DFS(nx,ny);
      }
  }
  return ret;
}

int main(){
  int i,j;
  scanf("%d %d",&N,&M);
  for(i=0;i<N;i++){
    for(j=0;j<M;j++){
      scanf("%d",&arr[i][j]);
      dp[i][j] = -1;
    }
  }
  // ans = BFS();
  printf("%d",DFS(N-1,M-1));
}
