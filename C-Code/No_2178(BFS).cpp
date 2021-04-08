#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int arr[101][101];  //미로값을 입력.
int check[101][101];  //방문 체크겸 count누적
int xi[4] = {0,1,0,-1}; //4방향탐색
int yi[4] = {1,0,-1,0};
int n,m;
queue<pair<int,int>> Q;

int bfs(){
  int x,y,i,nx,ny;
  while(!Q.empty()){
    x = Q.front().first;
    y = Q.front().second;
    Q.pop();
    if(x ==n && y ==m)  //n,m 목적지에 도착하면 종료
      break;
    for(i=0;i<4;i++){
      nx = x +xi[i];
      ny = y +yi[i];
      if((nx>=1 && nx<=n) && (ny>=1 && ny<=m)){ //범위확인
        if(arr[nx][ny]&&check[nx][ny]==0){  //경로와 방문유무확인
          Q.push(make_pair(nx,ny));
          check[nx][ny] = check[x][y]++;    //방문체크 + 경로까지의 거리
        }
      }
    }
  }
  return check[n][m];
}

int main(){
  int i,j,in=0,answer=0;
  scanf("%d %d",&n,&m);

  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      scanf("%1d",&in); //경로 설
      arr[i][j] = in;
    }
  }
  Q.push(make_pair(1,1));
  check[1][1]=1;
  answer=bfs();
  printf("%d",answer);
  return 0;
}
