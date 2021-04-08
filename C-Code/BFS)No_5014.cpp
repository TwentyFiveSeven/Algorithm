#include<iostream>
#include<queue>

using namespace std;

queue<int> Q;
int check[1000001];
int jump[2];
int F,S,G,U,D;

int bfs(){
  int i,j,temp=0;
  check[S] = 1;
  while(!Q.empty()){
    i = Q.front();
    Q.pop();
    for(j=0;j<2;j++){ // 위 , 아래로 이동 상황을 고려.
      temp = i + jump[j];
      if(temp>=1&&temp<=F&&!check[temp]){
        Q.push(temp);
        check[temp] = check[i]+1;
      }
    }
  }
  if(check[G]!=0) // check =0 이라면 도달할 수 없는 곳이다.
    return check[G]-1;
  else
    return -1;
}

int main(){
  int i,j,ans=0;
  scanf("%d %d %d %d %d",&F,&S,&G,&U,&D);
  jump[0] = U;
  jump[1] = -D;
  Q.push(S);
  ans = bfs();

  if(ans!=-1)
    printf("%d",ans);
  else
    printf("use the stairs");

    return 0;
}
