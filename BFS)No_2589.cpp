#include<iostream>
#include<queue>

using namespace std;
queue<pair<int,int>> Q;
int arr[51][51];
int check[51][51];
int xi[4] = {1,-1,0,0};
int yi[4] = {0,0,-1,1};
int n,m;

int bfs(int ansx,int ansy){
  int i,j,x,y,nx,ny,maxN=0;

  Q.push(make_pair(ansx,ansy));
  check[ansx][ansy] = 1;

  while(!Q.empty()){
    x = Q.front().first;
    y = Q.front().second;
    Q.pop();
    for(i=0;i<4;i++){ // 네 방향을 확인한다.
      nx = x + xi[i];
      ny = y + yi[i];
      if(nx>=1&&nx<=n&&ny>=1&&ny<=m){
        if(arr[nx][ny]==1&&!check[nx][ny]){
          Q.push(make_pair(nx,ny));
          check[nx][ny] = check[x][y] +1; // 현재 온곳의 이전 위치에서의 시간+1 을 하므로서 최단경로로 이동한다.
          if(check[nx][ny]>maxN)  // 시작부터 끝까지의 최단거리에서 가장 긴 시간을 찾는다.
            maxN = check[nx][ny];
        }
      }
    }
  }
  return maxN-1;  //첫 방문한 곳은 0시간이지만 효율적 코딩을 위해 1시간으로 잡았으므로 -1 해준다.
}


int main(){
  int i,j,tmp=0,maxA=0,temp=0,k,l;

  scanf("%d %d",&n,&m);
  scanf("%c",&temp);    // enter입력을 방지

  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      scanf("%c",&temp);
      if(temp == 'L')
        arr[i][j] = 1;
    }
    scanf("%c",&temp);    // enter입력을 방지
  }

  for(i=1;i<=n;i++){    //2중 for문을 통해 모든 육지를 시작점으로 하여 최단경로로 이동 했을 때 가장 긴 시간을 찾는다.
    for(j=1;j<=m;j++){
      if(arr[i][j]){
        tmp = bfs(i,j);
        if(tmp>maxA)
          maxA = tmp;
        for(k=1;k<=n;k++){
          for(l=1;l<=m;l++){
            check[k][l] =0;
          }
        }
      }
    }
  }
  printf("%d",maxA);

  return 0;
}
