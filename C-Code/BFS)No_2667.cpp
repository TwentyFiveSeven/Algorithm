#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N,arr[25][25],check[25][25],xi[4] = {0,0,1,-1},yi[4] = {1,-1,0,0};
vector<pair<int,int>> Q;
vector<int> V;

void bfs(int i,int j){
  int x=0,y=0,nx,ny,ret = 0;
  Q.push_back(make_pair(i,j));
  int save = 0;
  while(!Q.empty()){
    x = Q.back().first;
    y = Q.back().second;
    Q.pop_back();
    if(check[x][y]) continue;
    check[x][y] = 1;
    ret++;
    for(int i=0;i<4;i++){
      nx = x+xi[i];
      ny = y+yi[i];
      if(nx>=0 && nx <N && ny >=0 && ny<N){
        if(arr[nx][ny] && !check[nx][ny]){
          Q.push_back(make_pair(nx,ny));
        }
      }
    }
  }
  V.push_back(ret);
}


int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      scanf("%1d",&arr[i][j]);
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(arr[i][j] && !check[i][j]){
        bfs(i,j);
      }
    }
  }
  sort(V.begin(),V.end());
  int size = V.size();
  printf("%d\n",V.size());
  for(int i=0;i<size;i++){
    printf("%d\n",V[i]);
  }
  return 0;
}
