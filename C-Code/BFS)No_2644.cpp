#include<iostream>
#include<queue>
using namespace std;

int arr[101][101];
int check[101][101];  //check를 활용하기 위해 pair를 사용해야한다.
int n;
queue<pair<int,int>> Q;

int bfs(int ansx,int ansy){
  int i,j,count =0,k=0;
  Q.push(make_pair(ansx,ansy)); // pair를 이용해서 ansy 를 i값으로 사용, ansx값은 check값으로 사용
  while(!Q.empty()){
    i=Q.front().second;
    k=Q.front().first;
    if(i==ansx&&check[k][i]!=0){ // 처음은 ansy로 시작하기 때문에 i 가 ansx가 되는 시점을 구해서 그 때의 check값을 가져오면 된다.
      return check[k][i]; // 현재 ansx로 오기 전의 i,ansx의 check 값을 return 해준다.
    }
    Q.pop();
    for(j=1;j<=n;j++){
      if(arr[i][j]==1&&!check[i][j]){
        check[i][j] = check[k][i]+1;
        check[j][i] = check[k][i]+1;  //양방향으로 한쪽을 방문하면 반대지만 같은 방향은 탐색 X
        Q.push(make_pair(i,j));
      }
    }
  }
  return -1;
}

int main(){
  int i,j,m,x=0,y=0,ansx=0,ansy=0,answer=0;

  scanf("%d",&n);
  scanf("%d %d",&ansx,&ansy);
  scanf("%d",&m);

  for(i=1;i<=m;i++){
    scanf("%d %d",&x,&y);
    arr[x][y] = 1;
    arr[y][x] = 1;
  }
  answer = bfs(ansx,ansy);
  printf("%d",answer);

  return 0;
}
