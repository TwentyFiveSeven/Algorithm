#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

struct map{
  int x,y,z;
};

int N,M;
int arr[1000][1000],check[1000][1000][2];
int xi[4] = {0,0,1,-1};
int yi[4] = {1,-1,0,0};

int bfs(){
  queue<map> Q;
  Q.push({0,0,0});
  check[0][0][0] = 1;
  while(!Q.empty()){
    int x = Q.front().x;
    int y = Q.front().y;
    int w = Q.front().z;
    Q.pop();
    if(x == N-1 && y == M-1) return check[x][y][w];
    for(int i=0;i<4;i++){
      int nx = x+xi[i];
      int ny = y+yi[i];
      if(nx>=0 && nx<N && ny>=0 && ny<M)
        if(!check[nx][ny][w]){
          if(arr[nx][ny]&&w==0){
            check[nx][ny][1] = check[x][y][w]+1;
            Q.push({nx,ny,1});
          }else if(!arr[nx][ny]){
            check[nx][ny][w] = check[x][y][w]+1;
            Q.push({nx,ny,w});
          }
        }
    }
  }
  return -1;
}

int main(){
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    for(int j = 0;j<M;j++){
      scanf("%1d",&arr[i][j]);
    }
  }
  printf("%d",bfs());
  return 0;
}
