#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

queue<pair<int,int>> Q;

int arr[101][101];
int check[101][101];
int ans[100001];
int xi[4] = {1,-1,0,0};
int yi[4] = {0,0,1,-1};
int n,m;

int bfs(){
  int i,j,x,y,nx,ny,count=0;

  while(!Q.empty()){
    x = Q.front().first;
    y = Q.front().second;
    Q.pop();
    for(i=0;i<4;i++){
      nx = x + xi[i];
      ny = y + yi[i];
      if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!arr[nx][ny]&&!check[nx][ny]){ //상하좌우 block을 확인하여 방문하지않고, 영역에 해당하는부분을 탐색
        Q.push(make_pair(nx,ny));
        check[nx][ny] = 1;
        count++;
      }
    }
  }
  if(!count)
    count =1;
  return count;
}

int main(){
  int i,j,x1=0,x2=0,y1=0,y2=0,num,count=0,k=0;
  scanf("%d %d %d", &m,&n,&k);

  for(num=1;num<=k;num++){
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    for(i=x1+1;i<=x2;i++){
      for(j=y1+1;j<=y2;j++){
        arr[i][j] = 1;
      }
    }
  }

  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      if(!arr[i][j]&&!check[i][j]){   //아직 방문하지 않은 영역을 탐색한다.
        Q.push(make_pair(i,j));
        ans[count++] = bfs();       //Q가 empty가 될 때 까지 돌고 나오면 현재 영역의 넓이를 return받아서 저장한다.
      }
    }
  }
   sort(ans,ans+count);
   printf("%d\n",count);
  for(i=0;i<count;i++){
      printf("%d ",ans[i]);
  }
  return 0;
}
