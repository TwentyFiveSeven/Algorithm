#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
vector<int> save[100001];
int root[100001],check[100001],N;

void dfs(int start){
  check[start] = 1;
  int size = save[start].size();
  for(int i=0;i<size;i++){
    if(!check[save[start][i]]){
      root[save[start][i]] = start;
      dfs(save[start][i]);
    }
  }
}

int main(){
  int x,y;
  scanf("%d",&N);
  for(int i=0;i<N-1;i++){
    scanf("%d %d",&x,&y);
    save[x].push_back(y);
    save[y].push_back(x);
  }
  dfs(1);
  for(int i=2;i<=N;i++){
    printf("%d\n",root[i]);
  }
  return 0;
}
