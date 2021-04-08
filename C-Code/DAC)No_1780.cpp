#include<iostream>
using namespace std;
int arr[2188][2188],ans0,ans1,ans11;
int xi[9] = {0,0,0,1,2,1,2,1,2};
int yi[9] = {0,1,2,0,0,1,2,2,1};
int checkN(int n,int x,int y){
  int row = x, col = y;
  int check = arr[row][col];
  for(int i=row;i<=row+n-1;i++){
    for(int j=col;j<=col+n-1;j++){
      if(arr[i][j] != check) return -2;
    }
  }
  return check;
}

void find(int n,int x,int y){
  int val = checkN(n,x,y);
  if(val != -2){
    if(val == 0) {
      ans0++;
    }
    else if(val == 1){
      ans1++;
    }
    else {
      ans11++;
    }
    return;
  }
  if(n/3 ==0) return;
  for(int i=0;i<9;i++)
    find(n/3,x + xi[i]* n/3, y+yi[i]*n/3);
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
  printf("%d\n%d\n%d",ans11,ans0,ans1);
  return 0;
}
