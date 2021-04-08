#include<iostream>
#include<vector>
using namespace std;
int sdoku[9][9];
int size=0;
vector<pair<int,int>> V;

void print(){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      printf("%d ",sdoku[i][j]);
    }
    printf("\n");
  }
  exit(0);
}

int promising(int x,int y){
  for(int i=0;i<9;i++){
    if(i == y) continue;
    if(sdoku[x][i] == sdoku[x][y]) return 0;
  }
  for(int i=0;i<9;i++){
    if(i == x) continue;
    if(sdoku[i][y] == sdoku[x][y]) return 0;
  }
  int nx = (x/3)*3;
  int ny = (y/3)*3;
  for(int i=nx;i<nx+3;i++){
    for(int j=ny;j<ny+3;j++){
      if(i == x && j == y) continue;
      if(sdoku[i][j] == sdoku[x][y]) return 0;
    }
  }
  return 1;
}

void Fsdoku(int depth){
  if(size == depth){
    print();
  }
  int x = V[depth].first;
  int y = V[depth].second;
  for(int i=1;i<=9;i++){
    sdoku[x][y] = i;
    if(promising(x,y)){
      Fsdoku(depth+1);
    }
    sdoku[x][y] = 0;
  }
}

int main(){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      scanf("%d",&sdoku[i][j]);
      if(!sdoku[i][j]){
        V.push_back(make_pair(i,j));
      }
    }
  }
  size = V.size();
  Fsdoku(0);
}
