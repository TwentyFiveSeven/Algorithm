#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int check[200001];
queue<int> Q;
int ans,n,k;

void bfs(){                 // 전체 탐색은 아니지만 답을 찾을 때 까지 전체를 탐색해서 답을 구한다.
  int i,j,minus,plus,doub,value=0;

  while(!Q.empty()){
    value = Q.front();
    Q.pop();
    if(value==k){
      ans = check[value];
      return;
    }
    minus = value-1;
    plus = value+1;
    doub = value*2;

    if(check[minus]==0&&minus<=100000&&minus>=0){   //현재 값에서 -1한 값이 0 ~ 100000 사이에 있고 방문하지않은 곳을 확인.
      Q.push(minus);                                //방문 하지않았다면 Q에 저장하고
      check[minus] = check[value]+1;                //vlaue-1 값을 방문하는데 걸리는 count값을 저장한다.
    }
    if(check[plus]==0&&plus<=100000&&plus>=0){      // 위와 동일한 방법.
      Q.push(plus);
      check[plus] = check[value]+1;
    }
    if(check[doub]==0&&doub<=100000&&doub>=0){
      Q.push(doub);
      check[doub] = check[value]+1;
    }
  }
}

int main(){
  int i,j,count=0,num=0;

  scanf("%d %d",&n,&k);
  Q.push(n);
  bfs();

  printf("%d",ans);
  return 0;
}
