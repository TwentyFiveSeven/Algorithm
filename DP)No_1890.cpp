#include<iostream>
using namespace std;

int N,arr[100][100];
long long dp[100][100];
int xi[2] = {0,1};
int yi[2] = {1,0};

long long find(int x,int y){
  if(x == N-1 && y == N-1) return 1;
  if(dp[x][y] != -1) return dp[x][y];
  dp[x][y] = 0;

  for(int i=0;i<2;i++){
    int nx = x + xi[i]*arr[x][y];
    int ny = y + yi[i]*arr[x][y];
    if(nx>=0&&nx<N&&ny>=0&&ny<N){
      dp[x][y] += find(nx,ny);
    }
  }
  return dp[x][y];
}

int main(){
  int i,j;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      scanf("%d",&arr[i][j]);
      dp[i][j] = -1;
    }
  }
  printf("%lld",find(0,0));
  return 0;
}
