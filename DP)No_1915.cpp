#include<iostream>
using namespace std;
int arr[1000][1000];
int main(){
  int N,M,Max=0;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      scanf("%1d",&arr[i][j]);
      if(arr[i][j])
        if(i-1>=0 && arr[i-1][j])
          arr[i][j] = arr[i-1][j]+1;
    }
  }
  for(int i=0;i<N;i++){
    for(int j=Max+1;j<=i+1;j++){
      int count = 0;
      for(int k=0;k<M;k++){
        if(arr[i][k] >=j)
          count++;
        else
          count = 0;
        if(count == j && j>Max){
          Max = j;
          break;
        }
      }
    }
  }
  printf("%d",Max*Max);
  return 0;
}
