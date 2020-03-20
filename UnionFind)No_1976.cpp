#include<iostream>
using namespace std;

int N,M,city[201][201],parent[201];

void join(int l, int r){

}

int main(){
  int a,b;
  scanf("%d %d",&N,&M);
  for(int i=1;i<=N;i++)
    parent[i] = i;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      scanf("%d",&a);
      if(a == 1){
        if(parent[j] > parent[i])
          parent[j] = parent[i];
        else
          parent[i] = parent[j];

      }
    }
  }
  int First,Second;
  scanf("%d",&First);
  for(int i=1;i<M;i++){
    scanf("%d",&Second);
    if(parent[First] != parent[Second]){
      printf("NO");
      return 0;
    }
    First = Second;
  }
  printf("YES");
  return 0;
}
