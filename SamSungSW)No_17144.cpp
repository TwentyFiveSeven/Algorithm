#include<iostream>
#include<vector>
using namespace std;
int R,C,T,x1,x2,arr[50][50];
int xi[4] = {0,0,1,-1}, yi[4] = {1,-1,0,0};
vector<pair<int,int>> V;

void spread(){
  int temp[50][50]={0},count=0,val,nx,ny;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      count = 0;
      if(arr[i][j] >=5){
        val = arr[i][j]/5;
        for(int k=0;k<4;k++){
          nx = i + xi[k];
          ny = j + yi[k];
          if(nx >=0 && nx <R && ny >=0 && ny<C && arr[nx][ny] != -1){
            temp[nx][ny] += val;
            count++;
          }
        }
        arr[i][j] -= val*count;
      }
    }
  }
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      if(arr[i][j] != -1)
        arr[i][j] +=temp[i][j];
    }
  }
}

void cleaning(){
  int i;
  arr[x1-1][0] = 0; //상단부분
  for(i=x1-1;i>0;i--) arr[i][0] = arr[i-1][0];
  for(i=0;i<C-1;i++) arr[0][i] = arr[0][i+1];
  for(i=0;i<x1;i++) arr[i][C-1] = arr[i+1][C-1];
  for(i=C-1;i>=2;i--) arr[x1][i] = arr[x1][i-1];
  arr[x1][1] = 0;

  arr[x2+1][0] = 0; //하단부분
  for(i=x2+1;i<R-1;i++) arr[i][0] = arr[i+1][0];
  for(i=0;i<C-1;i++) arr[R-1][i] = arr[R-1][i+1];
  for(i=R-1;i>=x2+1;i--) arr[i][C-1] = arr[i-1][C-1];
  for(i=C-1;i>=2;i--) arr[x2][i] = arr[x2][i-1];
  arr[x2][1] = 0;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int sum =0;
  cin>>R>>C>>T;
  for(int i=0;i<R;i++)
    for(int j=0;j<C;j++){
      cin>>arr[i][j];
      if(x1 == 0 && arr[i][j] == -1){
        x1 = i, x2 = i+1;
      }
    }
  while(T--){
    spread();
    cleaning();
  }
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      if(arr[i][j] != -1 && arr[i][j])
        sum += arr[i][j];
    }
  }
  cout<<sum;
  return 0;
}
