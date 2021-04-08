#include<iostream>
#include<algorithm>
using namespace std;
int arr[1000][1000];
int main(){
  int N,M,Max =0;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
      scanf("%1d",&arr[i][j]);
  for(int i=1;i<N;i++)
    for(int j=1;j<M;j++)
      if(arr[i][j])
        arr[i][j] += min({arr[i-1][j],arr[i][j-1],arr[i-1][j-1]});
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
      Max = max(Max,arr[i][j]);
  printf("%d",Max*Max);
  return 0;
}
