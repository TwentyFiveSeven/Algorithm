#include<iostream>
#include<vector>
using namespace std;
int N,M;
int arr[100][100],check[100];

vector<int> V;

int bfs(int start){
  int ret = 0;
  V.push_back(start);
  while(!V.empty()){
    start = V.front();V.erase(V.begin());
    check[start] = 1;
    ret++;
    for(int i=0;i<N;i++){
      if(arr[start][i] && !check[i]){
        V.push_back(i);
        check[i] = 1;
      }
    }
  }
  return ret;
}

int main(){
  int a,b;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    scanf("%d %d",&a,&b);
    arr[a-1][b-1] = arr[b-1][a-1] = 1;
  }
  printf("%d",bfs(0)-1);
  return 0;
}
