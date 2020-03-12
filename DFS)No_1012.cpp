#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

vector<pair<int,int>> V;
int T,N,M,K,X,Y,arr[50][50],check[50][50];
int xi[4] = {0,0,-1,1},yi[4] = {1,-1,0,0};

void dfs(int i, int j){
  V.push_back(make_pair(i,j));
  while(!V.empty()){
    int x = V.back().first;
    int y = V.back().second;
    V.pop_back();
    if(check[x][y]) continue;
    check[x][y] = 1;
    for(int i=0;i<4;i++){
      int nx = x + xi[i];
      int ny = y + yi[i];
      if(nx>=0&&nx<N&&ny>=0&&ny<M){
        if(arr[nx][ny] && !check[nx][ny]){
          V.push_back(make_pair(nx,ny));
        }
      }
    }
  }
}


int main(){
  scanf("%d",&T);

  while(T--){
    int ret =0;
    scanf("%d %d %d",&N,&M,&K);
    for(int i=0;i<K;i++){
      scanf("%d %d",&X,&Y);
      arr[X][Y] = 1;
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if(arr[i][j]&&!check[i][j]){
          dfs(i,j);
          ret++;
        }
      }
    }
    printf("%d\n",ret);
    memset(check,0,sizeof(check));
    memset(arr,0,sizeof(arr));
  }
  return 0;
}
