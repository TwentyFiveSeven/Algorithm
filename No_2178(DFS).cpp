#include <iostream>
#include <algorithm>
using namespace std;

int arr[101][101];
int check[101][101];
long long ans[101];
int xi[4] = {0,1,-1,0};
int yi[4] = {1,0,0,-1};
int n,m,input;

int bfs(int i,int j,int count){
  int nx,ny,k;
  count++;
  for(k=0;k<4;k++){
    nx = i+xi[k];
    ny = j+yi[k];
    if(arr[nx][ny]&&!check[nx][ny]){
      check[nx][ny] =1;
      if(nx==n&&ny==m){
        check[n][m]=0;
        count++;
        ans[input++]=(long long)count;
        return 0;
      }
      bfs(nx,ny,count);
    }
  }
}

int main(){
  int i,j;

  scanf("%d %d",&n,&m);
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      scanf("%1d",&arr[i][j]);
    }
  }
  check[1][1] = 1;
  bfs(1,1,0);
  sort(ans,ans+input);
  printf("%lld",ans[0]);
  return 0;
}

/*
110111
010101
111101
100001
111111
*/
