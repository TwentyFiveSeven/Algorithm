#include<iostream>
using namespace std;
int arr[65][65];
int xi[4] = {0,0,1,1};
int yi[4] = {0,1,0,1};
int check(int n,int x,int y){
  int color = arr[x][y];
  for(int i=x;i<=x+n-1;i++){
    for(int j=y;j<=y+n-1;j++){
      if(arr[i][j] != color) return -1;
    }
  }
  return color;
}

void dac(int n,int x,int y){
  int val = check(n,x,y);
  if(val != -1){
    printf("%d",val);
    return;
  }
  if(n/2 == 0) return;
  printf("(");
  for(int i=0;i<4;i++){
    dac(n/2, x+xi[i]*n/2, y+yi[i]*n/2);
  }
  printf(")");
  return;
}

int main(){
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      scanf("%1d",&arr[i][j]);
    }
  }
  dac(n,1,1);
  return 0;
}
