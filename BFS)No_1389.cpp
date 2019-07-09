#include<iostream>
#include<queue>

using namespace std;
int arr[101][101];
int check[101];

queue<int> Q;

int n,m;

int bfs(int ans){
  int i,j,sum=0;
  Q.push(ans);
  check[ans] = 0;
  
  while(!Q.empty()){
    i = Q.front();
    Q.pop();
    for(j=1;j<=n;j++){
      if(arr[i][j]==1&&!check[j]&&j!=ans){  // 시작 지점은 제외.
        Q.push(j);
        check[j] = check[i]+1;  // 한번 지나간 j는 다시 지나가지않는다.
      }
    }
  }
  for(i=1;i<=n;i++){
    sum += check[i];  // 시작 점부터 나머지 점까지의 관계 수를 다 더한다.
  }
  return sum;
}


int main(){
  int i,j,x=0,y=0,min=999999,save=999999,tmp=0;
  scanf("%d %d",&n,&m);

  for(i=1;i<=m;i++){
    scanf("%d %d",&x,&y);
    arr[x][y] = 1;
    arr[y][x] = 1;
  }
  for(i=1;i<=n;i++){
    tmp = bfs(i);
    if(tmp<min){
      min = tmp;
      save = i;
    }
    for(j=1;j<=n;j++)
      check[j]=0;
  }

  printf("%d",save);

  return 0;
}
