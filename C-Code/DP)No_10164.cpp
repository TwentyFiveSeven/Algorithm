#include<iostream>
using namespace std;
int arr[15][15];
int main(){
  int N,M,K,X,Y;
  cin>>N>>M>>K;
  if(K==0) X = N-1, Y = M-1;
  else X = (K-1)/M, Y = (K-1)%M;
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
      arr[i][j] = 1;

  for(int i=1;i<=X;i++){
    for(int j=1;j<=Y;j++){
      arr[i][j] = arr[i-1][j]+arr[i][j-1];
    }
  }
  if(K==0|| K==N*M){
    cout<<arr[N-1][M-1];
    return 0;
  }
  for(int i=X+1;i<N;i++){
    for(int j=Y+1;j<M;j++){
      arr[i][j] = arr[i-1][j]+arr[i][j-1];
    }
  }
  cout<<arr[X][Y]*arr[N-1][M-1];
  return 0;
}
