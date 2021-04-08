#include<iostream>
#include<vector>
using namespace std;
vector<int> V;
int arr[1000][1000],check[1000];
int N,M,start;

void dfs(int start){
  V.push_back(start);
  while(!V.empty()){
    start = V.back();V.pop_back();
    if(check[start]) continue;
    printf("%d ",start+1);
    check[start] = 1;
    for(int i=N-1;i>=0;i--){
      if(arr[start][i]){
        V.push_back(i);
      }
    }
  }
}

void bfs(int start){
  V.push_back(start);
  while(!V.empty()){
    start = V.front();V.erase(V.begin());
    if(check[start]) continue;
    printf("%d ",start+1);
    check[start] = 1;
    for(int i=0;i<N;i++){
      if(arr[start][i] && !check[i]){
        V.push_back(i);
      }
    }
  }
}

int main(){
  int a,b;
  scanf("%d %d %d",&N,&M,&start);
  for(int i=0;i<M;i++){
    scanf("%d %d",&a,&b);
    arr[a-1][b-1] = arr[b-1][a-1] = 1;
  }
  dfs(start-1);
  printf("\n");
  for(int i=0;i<N;i++) check[i] = 0;
  bfs(start-1);
  return 0;
}
