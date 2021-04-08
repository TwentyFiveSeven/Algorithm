#include<iostream>
using namespace std;

int arr[500][500],dp[500][500],N,Max;
int xi[4] = {0,0,-1,1};
int yi[4] = {1,-1,0,0};

int DFS(int x,int y){
  if(dp[x][y] >= 1 ) return dp[x][y]+1;
  int ans = 1;
    for(int i=0;i<4;i++){
      int nx = x +xi[i];
      int ny = y +yi[i];
      if(nx>=0&&nx<N&&ny>=0&&ny<N){
        if(arr[nx][ny]>arr[x][y]){
          ans = max(ans,DFS(nx,ny));  // 4방향중 가장 큰 count를 준 수를 선택
        } //위 방법은 지나가면서 count수를 더해 가는 것이 아니라 현재 위치에서
      } //count할 수 있는 최대의 수를 입력하는 것이다.
    }
    dp[x][y] = ans;
    if(ans+1>Max) Max = ans+1;
    return ans+1;
}

int main(){
  int i,j;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    for(j=0;j<N;j++){
      scanf("%d",&arr[i][j]);
      dp[i][j] =-1; //메모이제이션의 포인트
    }
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(dp[i][j]==-1){ // 방문하지 않은 것만 방문.
        DFS(i,j);
      }
    }
  }
  printf("%d",Max-1);
  return 0;
}
