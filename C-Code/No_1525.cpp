#include<iostream>
using namespace std;

int xi[4] = {0,0,1,-1};
int yi[4] = {1,-1,0,0};

int dfs(int arr[][3],int save,int count){
  printf("%d %d\n",count,save);
  if(save == 8)
    printf("%d",count);
  int x = save/3;
  int y = save%3;
  int temp[3][3];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      temp[i][j] = 0;
      temp[i][j] = arr[i][j];
    }
  }
  for(int i=0;i<4;i++){
    int nx = x + xi[i];
    int ny = y + yi[i];
    if(nx>=0&& nx<3&&ny>=0&&ny<3){
      if(arr[nx][ny] != nx*3+ny){
        int tmp = arr[nx][ny];
        arr[nx][ny] = 0;
        arr[x][y] = tmp;
        dfs(arr,nx*3+ny,count+1);
        for(int i=0;i<3;i++){
          for(int j=0;j<3;j++){
            arr[i][j] = temp[i][j];
          }
        }
      }
    }
  }
}


int main(){
  int arr[3][3];
  int i,j,save=0;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      arr[i][j] = 0;
      scanf("%d",&arr[i][j]);
      if(arr[i][j] == 0) save = i*3+j;
    }
  }
  printf("save : %d\n",save);
  dfs(arr,save,0);
}
