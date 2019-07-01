#include<iostream>
#include<queue>
#include<list>
using namespace std;

int arr[1001][1001];
int check[1001];
int check2[1001];
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
        check[j]=1;   //탐색하는 과정에서 Q에 push해줄 때 check를 해준다.
      }
    }
  }
}

void dfs(int k){
  int i,j,tmp=0,count=0;
  L.push_front(k);

  while(!L.empty()){
    tmp = L.front();
    if(!check2[tmp]){   //정점을 지나가지않았을 때만 출력 후 check를 해준다. (중요)
      printf("%d ",L.front());
      check2[tmp]=1;
    }
    L.pop_front();
    for(j=n;j>=1;j--){
      if(arr[tmp][j]&&!check2[j]){
        L.push_front(j);            //탐색하는 과정에서 List에 Push를 해줄 때 check를 함께 하지않는다.(현재 위치를 최우선적으로 고려하기위함)
      }
    }
  }
}

int main(){
  int i,j,k=0,p1=0,p2=0;

  scanf("%d %d %d",&n,&m,&k);

  for(i=1;i<=m;i++){
    scanf("%d %d",&p1,&p2);
    arr[p1][p2] = 1;
    arr[p2][p1] = 1;
  }
  dfs(k);
  printf("\n");
  bfs(k);

  return 0;
}
