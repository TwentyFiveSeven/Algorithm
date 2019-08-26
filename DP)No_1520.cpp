#include<cstdio>
using namespace std;
int arr[500][500],N,M,dp[500][500];
int xi[4] = {0,0,1,-1};
int yi[4] = {1,-1,0,0};

int DFS(int x,int y){ //DFS,BFS만으로는 재방문 알고리즘에 큰 어려움이 있기 때문에 재귀(check)를 통해 효과적인 방문.
  if(x == 0 && y ==0) return 1;
  if(dp[x][y] != -1) return dp[x][y]; //dp를 이용해 check를 대신한다.
  dp[x][y] = 0;
  for(int i=0;i<4;i++){
    int nx = x+xi[i];
    int ny = y+yi[i];
    if(nx>=0&&nx<N&&ny>=0&&ny<M)
      if(arr[nx][ny]>arr[x][y]){
        dp[x][y] += DFS(nx,ny);
      }
  }
  return dp[x][y];
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
  printf("%d",DFS(N-1,M-1));
  return 0;
}
