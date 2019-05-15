#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int ans[625];
int arr[26][26];
int check[26][26];
int xi[4]={0,0,-1,1};
int yi[4]={1,-1,0,0};
int n,save1=1,save2=1,num,count;
queue<pair<int,int>> Q;

void bfs()    //Q의 입력된 지점부터 탐색시작
{
  int nx=0,ny=0,i,j,k=0,x=0,y=0;
  while(!Q.empty()) //Q가 비었다면 단지 탐색끝 return
  {
    x = Q.front().first;
    y = Q.front().second;
    check[x][y]=1;
    count++;
    Q.pop();
    for(k=0;k<4;k++)//Q에서 나온 지점으로부터 4개 방향을 모두 확인한다.
    {
      nx=x+xi[k];
      ny=y+yi[k];
      if(nx>=1 && nx<=n && ny>=1 && ny<=n && arr[nx][ny]==1 && !check[nx][ny])
      {
        Q.push(make_pair(nx,ny));
        check[nx][ny]=1;
      }
    }
  }
  num++;
  ans[num]=count;
  count =0;
}


int main()
{
  int i,j,k=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      scanf("%1d",&arr[i][j]);
      if(arr[i][j]==1)
        check[i][j]=0;
      else
        check[i][j]=1;
    }
  }
  for(i=1;i<=n;i++){    //bfs로 완전탐색
    for(j=1;j<=n;j++){
      if(arr[i][j]==1 && !check[i][j])
      {
        Q.push(make_pair(i,j)); //아파트단지이고 방문하지않은 곳을 Q에 넣어준다.
        bfs();
      }
    }
  }
  printf("%d\n",num);
  sort(ans+1,ans+num);
  for(i=1;i<=num;i++)
    printf("%d\n",ans[i]);
  return 0;
}
