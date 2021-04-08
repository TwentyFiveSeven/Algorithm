#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int arr[500][500];
int check[500][500];
int xi[4] = {0,0,-1,1};
int yi[4] = {-1,1,0,0};
int n,m;
queue<pair<int,int>> Q;

void bfs()
{
  int i,j,x=0,y=0,nx=0,ny=0;
  while(!Q.empty())
  {
    x = Q.front().first;
    y = Q.front().second;
    Q.pop();
    check[x][y]=0;
    for(i=0;i<4;i++)
    {
      nx = x+xi[i];
      ny = y+yi[i];
      if(nx>=0 && nx<=(n-1) && ny>=0 && ny<m && arr[nx][ny]==1 && check[nx][ny]==1)
      {
        Q.push(make_pair(nx,ny));
        check[nx][ny]=0;
      }
    }
  }
}

int main(){
  int i,j,t,k=0,x=0,y=0,count=0;

  scanf("%d",&t);
  while((t--)>0)
  {
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<k;i++)
    {
      scanf("%d %d",&x,&y);
      arr[x][y]=1;
      check[x][y]=1;
    }

    for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
      {
        if(arr[i][j]==1&&check[i][j]==1)
        {
          Q.push(make_pair(i,j));
          bfs();
          count++;
        }
      }
    }
    printf("%d\n",count);
    count=0;
    for(i=0;i<n;i++)
      for(j=0;j<m;j++)
        arr[i][j]=0;
  }
  return 0;
}
