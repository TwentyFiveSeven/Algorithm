#include<iostream>
#include<queue>

using namespace std;

int arr[1001][1001];
int check[1001][1001];

int xi[4] = {1,-1,0,0};
int yi[4] = {0,0,1,-1};

queue<pair<int,int>> Q;

int allcount,checkcount,n,m,maxvalue;

void bfs(){
  int i,j,x,y,nx,ny;

  while(!Q.empty()&&(allcount!=checkcount)){
    x = Q.front().first;
    y = Q.front().second;
    Q.pop();
    for(i=0;i<4;i++){
      nx = x + xi[i];
      ny = y + yi[i];
      if(nx>=1&& nx<=n&&ny>=1&&ny<=m&&!arr[nx][ny]&&!check[nx][ny]){
        Q.push(make_pair(nx,ny));
        checkcount++;
        check[nx][ny] = check[x][y]+1;
        // printf("%d %d : %d\n",nx,ny, check[nx][ny]);
        maxvalue = check[nx][ny];
      }
    }
  }
  if(allcount==checkcount)
    printf("%d",maxvalue);
  else
    printf("-1");
}

int main(){
  int i,j;

  scanf("%d %d",&m,&n);
  allcount = n*m;

  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      scanf("%d",&arr[i][j]);
      if(arr[i][j] ==1){
        Q.push(make_pair(i,j));
        checkcount++;
      }else if(arr[i][j] ==-1){
        allcount--;
      }
    }
  }
  bfs();

  return 0;
}
