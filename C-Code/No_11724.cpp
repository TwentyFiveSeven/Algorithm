#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[1001][1001];
int check[1001];
int n,m;

void dfs(int i){  //dfs를 통해 연결되면서 지나가지않은 노드들을 탐색
  int j;
  check[i]=1;
  for(j=1;j<=n;j++)
  {
    if(arr[i][j]==1&&check[j]==0)
    {
        dfs(j);
    }
  }
}


int main()
{
  int i,j,input1=0,input2=0,count=0;
  scanf("%d %d",&n,&m);

  for(i=1;i<=m;i++)
  {
    scanf("%d %d",&input1,&input2);
    arr[input1][input2] = 1;
    arr[input2][input1] = 1;
  }
  for(i=1;i<=n;i++)
  {
      if(check[i]==0) //check가 0인 부분부터 탐색
      {
        count++;    //서로 떨어진 부분이 발견될 때마다 count++
        dfs(i);     //탐색의 시작인자i를 넘겨준다
      }
  }
  printf("%d",count);
}
