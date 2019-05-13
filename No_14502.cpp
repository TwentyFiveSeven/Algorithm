#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 9

int n,m,num;
int arr[MAX][MAX];
int tmp[MAX][MAX];
int xi[4] ={0,0,1,-1};
int yi[4] ={-1,1,0,0};

vector<pair<int, int>> virus;

void CopyMap(int(*a)[MAX],int(*b)[MAX])
{
  int i,j;
  for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
      a[i][j]=b[i][j];
}

void virusbfs()
{
    int i,j,x=0,y=0,k=0,nx=0,ny=0;
    int newarr[MAX][MAX];
    CopyMap(newarr,tmp);

    queue<pair<int,int>> q;
    for(int i=0;i<virus.size();i++)
      q.push(virus[i]);

    while(!q.empty())
    {
      x=q.front().first;
      y=q.front().second;
      q.pop();

      for(k=0;k<4;k++){
        nx = x+xi[k];
        ny = y+yi[k];
        if(1<=nx && nx<=n && 1<=ny && ny<=m)
        {
          if(newarr[nx][ny]==0)
          {
            newarr[nx][ny]=2;
            q.push(make_pair(nx,ny));
          }
        }
      }
    }
    int size=0;
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=m;j++)
      {
        if(newarr[i][j]==0)
          size++;
      }
    }
    if(size>num)
      num=size;
}

void setwall(int cnt)
{
  int i,j;
  if(cnt ==3)
  {
    virusbfs();
    return;
  }
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      if(tmp[i][j]==0)
      {
        tmp[i][j]=1;
        setwall(cnt+1);
        tmp[i][j]=0;
      }
    }
  }
}

int main(){
  int i,j,count=0;

  scanf("%d %d",&n,&m);
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      scanf("%d",&arr[i][j]);
      if(arr[i][j]==2)
      {
        virus.push_back(make_pair(i,j));
      }
    }
  }

  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      if(arr[i][j]==0)
      {
        CopyMap(tmp,arr);
        tmp[i][j]=1;
        setwall(1);
        tmp[i][j]=0;
      }
    }
  }
  printf("%d",num);
}
