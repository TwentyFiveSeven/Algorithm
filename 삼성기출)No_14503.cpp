#include<iostream>
using namespace std;

int xi[4] = {-1,0,1,0}; //0 북,1 동,2 남,3 서
int yi[4] = {0,1,0,-1};

int N,M,arr[50][50],count;

int dfs(int x,int y, int d){
  int temp=d;
  if(arr[x][y] == 1) return 0;
  if(arr[x][y] == 0) count++;
  arr[x][y] = 2;
  for(int i=1;i<=4;i++){
    temp-=1;
    if(temp<0) temp = 3;
    int nx = x+xi[temp];
    int ny = y+yi[temp];
    if(arr[nx][ny]==0){
      arr[x][y] +=dfs(nx,ny,temp);

    }
    if(i==4){
      temp-=1;
      if(temp==0) temp =4;
      else if(temp<0) temp=3;
      temp-=1;
      if(arr[x+xi[temp]][y+yi[temp]]==1){
        printf("%d",count);
        exit(0);
      }
      dfs(x+xi[temp],y+yi[temp],(temp+2)%4);
    }
  }
}

int main(){
  int i,j,d,x,y;
  scanf("%d %d",&N,&M);
  scanf("%d %d %d",&x,&y,&d);
  for(i=0;i<N;i++){
    for(j=0;j<M;j++){
      scanf("%d",&arr[i][j]);
    }
  }
  printf("%d\n",dfs(x,y,d));
  return 0;
}
