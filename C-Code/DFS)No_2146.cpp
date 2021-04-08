#include<iostream>
using namespace std;
int arr[101][101],check[101][101],N,Min = 2000000000;
int xi[4] = {0,0,1,-1};
int yi[4] = {1,-1,0,0};
void dfs(int x,int y,int v){
  if(check[x][y] == 1)
    return;
  check[x][y] = 1;
  arr[x][y] = v;
  for(int i=0;i<4;i++){
    int nx = x+xi[i];
    int ny = y+yi[i];
    if(nx >=0 && nx < N && ny >=0 && ny<N)
      if(arr[nx][ny] == 1&& check[nx][ny] == 0)
        dfs(nx,ny,v);
  }
}

int main(){
  cin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>arr[i][j];
    }
  }
  int count = 1;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(arr[i][j] ==1 && check[i][j] ==0){
        dfs(i,j,count);
        count++;
      }
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      int check =0;
      int val = arr[i][j];
      if(val != 0){
        for(int k=0;k<4;k++){
          int nx = i+xi[k], ny = j+yi[k];
          if(nx >=0 && nx<N && ny>=0 &&ny<N){
            if(arr[nx][ny] == 0 ){
              check = 1;
              break;
            }
          }
        }
        if(check == 1){
          for(int k=0;k<N;k++){
            for(int m=0;m<N;m++){
              if(arr[k][m] != val && arr[k][m] != 0){
                int check2 =0;
                for(int p=0;p<4;p++){
                  int nx = i+xi[p], ny = j+yi[p];
                  if(nx >=0 && nx<N && ny>=0 &&ny<N){
                    if(arr[nx][ny] == 0 ){
                      check2 = 1;
                      break;
                    }
                  }
                }
                if(check2 == 1){
                  Min = min(Min, abs(k-i)+abs(m-j));
                }
              }
            }
          }
        }
      }
    }
  }
  cout<<Min-1;
  return 0;
}
