#include<iostream>
#include<queue>
using namespace std;
int w=1,h=1,arr[51][51],check[51][51];
int xi[8] = {0,0,1,-1,-1,-1,1,1};
int yi[8] = {1,-1,0,0,1,-1,1,-1};
queue<pair<int,int>> Q;

int bfs(int ix,int iy){
  int x=0,y=0,nx,ny,i,j;
  Q.push(make_pair(ix,iy));
  check[ix][iy] = 1;
  while(!Q.empty()){
    x = Q.front().first;
    y = Q.front().second;
    Q.pop();
    for(i=0;i<8;i++){
      nx = x+xi[i];
      ny = y+yi[i];
      if(nx>=1&&nx<=h&&ny>=1&&ny<=w){
        if(arr[nx][ny] && !check[nx][ny]){
          check[nx][ny] =1;
          Q.push(make_pair(nx,ny));
        }
      }
    }
  }
}

int main(){
  int i,j,count=0;
  while(1){
    scanf("%d %d",&w,&h);
    if(!w&&!h) break;
    for(i=1;i<=h;i++){
      for(j=1;j<=w;j++){
        scanf("%d",&arr[i][j]);
      }
    }
    for(i=1;i<=h;i++){
      for(j=1;j<=w;j++){
        if(arr[i][j] && !check[i][j]){
          bfs(i,j);
          count++;
        }
      }
    }
    printf("%d\n",count);
    count=0;
    for(i=1;i<=h;i++){
      for(j=1;j<=w;j++){
        arr[i][j] = 0;
        check[i][j] = 0;
      }
    }
  }
  return 0;
}
