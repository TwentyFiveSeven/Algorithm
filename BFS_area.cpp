#include <iostream>
#include <queue>
using namespace std;

queue<pair<int,int>> Q;

int M,N;
const int dx[] = { -1,0,1,0 };
const int dy[] = { 0,-1,0,1 };

int bfs(int count){
  inf flag=0,i,j;
  pair<int,int> P;
  for(i=0;i<M;i++){
    for(j=0;j<N;j++){
      if(a[i][j]>0){
        P = make_pair(i,j);
        Q.push(P);
        a[i][j]=0;
        flag = 1;
        break;
      }
    }
    if(flag){
      break;
    }
  }

  do{
    P = Q.front();
    Q.pop();
    for()
    if(a[i][j]>0){

    }

  }while(!Q.empty())
}

int main(){
  int M,N,K,x1,y1,x2,y2,i,j,m;

  cin>>M>>N>>K;
  a = new int*[M];
  for(i=0;i<M;i++){
    a[i]=new int[N];
    for(j=0;j<N;j++){
      a[i][j]=j+7*i+1;
    }
  }

  for(m=0;m<K;m++){
    cin>>y1>>x1>>y2>>x2;
    for(i=x1;i<x2;i++){
      for(j=y1;j<y2;j++){
        a[i][j]=0;
      }
    }
  }

  for(i=0;i<M;i++){
    for(j=0;j<N;j++){
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }
  return 0;
}
