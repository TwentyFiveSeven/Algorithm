#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int w[16][16],dp[16][1<<16],N;
const int INF = 1e9;
int tsp(int now, int check){
  if(check == (1<<N)-1){
    if(w[now][0]!= 0) return w[now][0];
    return INF;
  }

  int& ret = dp[now][check];
  if(ret != -1) return ret;

  ret = INF;
  for(int next = 0;next<N;next++){
    if(check & (1<<next) || w[now][next] == 0) continue;
    ret = min(ret,tsp(next,check | (1<<next))+w[now][next]);
  }
  return ret;
}

int main(){
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      scanf("%d",&w[i][j]);
    }
  }
  memset(dp,-1,sizeof(dp));
  printf("%d",tsp(0,1));
  return 0;
}
