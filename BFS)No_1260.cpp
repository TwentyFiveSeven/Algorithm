#include<iostream>
#include<queue>
#include<list>
using namespace std;

int arr[1001][1001];
int check[1001];
list<int> L;
queue<int> Q;
int n,m;

void bfs(int k){
  int i,j,tmp =0;
  Q.push(k);check[k]=1;

  while(!Q.empty()){
    printf("%d ",Q.front());
    tmp = Q.front();
    Q.pop();
    for(j=1;j<=n;j++){
      if(arr[tmp][j]&&!check[j]){
        Q.push(j);
        check[j]=1;
      }
    }
  }
}

void dfs(){
}

int main(){
  int i,j,k=0,p1=0,p2=0;

  scanf("%d %d %d",&n,&m,&k);

  for(i=1;i<=m;i++){
    scanf("%d %d",&p1,&p2);
    arr[p1][p2] = 1;
    arr[p2][p1] = 1;
  }
  bfs(k);
}
