#include<iostream>
#include<queue>

using namespace std;

int arr[101][101];
int check[101][101];

int xi[4] = {1,-1,0,0};
int yi[4] = {0,0,1,-1};

queue<pair<int,int>> Q;
int allcount[101];
int checkcount[101];
int n,m,maxvalue,h;   //allcount = 모든 토마토의 수, checkcount = 익은 토마토의 수

void bfs(){
  int i,j,x,y,nx,ny;

  while(!Q.empty()&&(allcount!=checkcount)){    //Q가 비어있지않아도 모든 토마토가 익었으면 탐색 중지.
    x = Q.front().first;
    y = Q.front().second;
    Q.pop();
    for(i=0;i<4;i++){
      nx = x + xi[i];
      ny = y + yi[i];
      if(nx>=1&& nx<=n&&ny>=1&&ny<=m&&!arr[nx][ny]&&!check[nx][ny]){
        Q.push(make_pair(nx,ny));
        checkcount++;
        check[nx][ny] = check[x][y]+1;    //현재 토마토가 익은 날짜는 이전 토마토의 날짜+1 이다.
        maxvalue = check[nx][ny];     //마지막 check값이 가장 크기 때문에 계속해서 저장한다.
      }
    }
  }
  if(allcount==checkcount)  //익은 토마토의 수가 모든 토마토의 수와 같으면 값을 출력
    printf("%d",maxvalue);
  else                      //같지않다면 -1을 출력
    printf("-1");
}

int main(){
  int i,j,k;

  scanf("%d %d %d",&m,&n,&h);
  for(i=1;i<=h;i++){
    allcount[h] = n*m;
  }

  for(k=1;k<=h;k++){
    for(i=1;i<=n;i++){
      for(j=1;j<=m;j++){
        scanf("%d",&arr[h][i][j]);
        if(arr[h][i][j] ==1){
          Q.push(make_pair(i,j));
          checkcount[h]++;
        }else if(arr[h][i][j] ==-1){
          allcount[h]--;
        }
      }
    }
  }
  bfs();

  return 0;
}
