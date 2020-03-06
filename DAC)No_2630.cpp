#include<iostream>
using namespace std;
int arr[129][129],ans0,ans1;
int xi[4] = {0,0,1,1};
int yi[4] = {0,1,0,1};
int checkN(int n,int x,int y){
  int row = x, col = y;
  int check = arr[row][col];
  for(int i=row;i<=row+n-1;i++){
    for(int j=col;j<=col+n-1;j++){
      if(arr[i][j] != check) return -1;
    }
  }
  return check;
}

void find(int n,int x,int y){
  int val = checkN(n,x,y);
  if(val != -1){
    if(val == 0) {
      ans0++;
    }
    else {
      ans1++;
    }
    return;
  }
  if(n/2 ==0) return;
  for(int i=0;i<4;i++)
    find(n/2,x + xi[i]* n/2, y+yi[i]*n/2);
}

int main(){
  int n;
  scanf("%d",&n);
  for(int i = 1;i<=n;i++){
    for(int j=1;j<=n;j++){
      scanf("%d",&arr[i][j]);
    }
  }
  find(n,1,1);
  printf("%d\n%d",ans0,ans1);
  return 0;
}
