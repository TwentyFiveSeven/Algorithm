#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;

int Max=0,N;
queue<int> Q;
int arr[21][21];

void Make(int i, int j, int dx, int dy){
  while(!Q.empty()){
    int x = Q.front();
    if(arr[i][j] == 0){
      arr[i][j] = x;
      Q.pop();
      if(arr[i][j] > Max) Max = arr[i][j];
    }else if(arr[i][j] == x){
      arr[i][j] *=2;
      Q.pop();
      if(arr[i][j] > Max) Max = arr[i][j];
      i += dx;
      j += dy;
    }else{
      i += dx;
      j += dy;
    }
  }
}

void shift(int k){
  if(k == 0){
    for(int i =0;i<N;i++){
      for(int j = 0;j<N;j++){
        if(arr[i][j]){
          Q.push(arr[i][j]);
          arr[i][j] = 0;
        }
      }
      Make(i,0,0,1);
    }
  }else if(k == 1){
    for(int i=0;i<N;i++){
      for(int j = N-1;j>=0;j--){
        if(arr[i][j]){
          Q.push(arr[i][j]);
          arr[i][j] = 0;
        }
      }
      Make(i,N-1,0,-1);
    }
  }else if(k == 2){
    for(int i=0;i<N;i++){
      for(int j = 0;j<N;j++){
        if(arr[j][i]){
          Q.push(arr[j][i]);
          arr[j][i] = 0;
        }
      }
      Make(0,i,1,0);
    }
  }else{
    for(int i=0;i<N;i++){
      for(int j= N-1;j>=0;j--){
        if(arr[j][i]){
          Q.push(arr[j][i]);
          arr[j][i] =0;
        }
      }
      Make(N-1,i,-1,0);
    }
  }
}

void bf(int depth){
  if(depth == 5){
    return;
  }
  int tmp[21][21];
  memcpy(tmp,arr,sizeof(arr));
  for(int i=0;i<4;i++){
    shift(i);
    bf(depth+1);
    memcpy(arr,tmp,sizeof(tmp));
  }
}


int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      scanf("%d",&arr[i][j]);
    }
  }
  bf(0);
  printf("%d\n",Max);
  return 0;
}
