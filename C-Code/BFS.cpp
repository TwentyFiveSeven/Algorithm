#include <iostream>
#include <queue>
using namespace std;

int **a;
int n;
int *v;

void bfs(queue<int> Q){
  int i,j;
  do{
    i=Q.front();
    Q.pop();
    for(j=1;j<=n;j++){
      if(a[i][j]==1&& v[j]==0){
        printf("%d -> %d ",i,j);
        Q.push(j);
        v[j] = 1;
      }
    }
  }while(!Q.empty());
}

int main(){
  int i,j;
  queue<int> Q;

  cin>>n;
  a = new int*[n+1];
  for(i=1;i<=n;i++){
    a[i] = new int[n+1];
    for(j=1;j<=n;j++){
      cin>>a[i][j];
    }
  }
  v = new int[n+1];
  for(i=1;i<=n;i++)
    v[i] = 0;

  Q.push(1);v[1] = 1;
  bfs(Q);
  printf("\n");
  return 0;
}
