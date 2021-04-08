#include<iostream>
#include<queue>

using namespace std;

queue<pair<int,int>> Q;
int xi[8] = {1,2,2,1,-1,-2,-2,-1};
int yi[8] = {2,1,-1,-2,-2,-1,1,2};
int check[301][301];
int n;

int bfs(int destx,int desty){
  int i,j,x,y,nx,ny;

  while(!Q.empty()){
    x = Q.front().first;
    y = Q.front().second;
    Q.pop();
    if(x == destx && y ==desty){
      return check[x][y]-1;
    }
    for(i=0;i<8;i++){
      nx = x+xi[i];
      ny = y+yi[i];
      if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&!check[nx][ny]){   // 실수 연발 !!!!!!!!!! , 탐색 확인.
        Q.push(make_pair(nx,ny));
        check[nx][ny] = check[x][y]+1;
      }
    }
  }
  return check[x][y]-1;
}

int main(){
  int test=0,x1=0,y1=0,x2=0,y2=0,i,j,num=0;
  scanf("%d",&test);

  while(test--){
    scanf("%d",&n);
    scanf("%d %d",&x1,&y1);
    scanf("%d %d",&x2,&y2);
    x1++;x2++;y1++;y2++;  // index 1~300을 사용하기 위함

    Q.push(make_pair(x1,y1));
    check[x1][y1]=1;
    num = bfs(x2,y2);

    printf("%d\n",num);

    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
        check[i][j] =0;
      }
    }
    while(!Q.empty()){
      Q.pop();
    }
  }

  return 0;
}
