#include<iostream>
using namespace std;

int N,M,city[201][201],parent[201];

int Find(int a){
  if(a == parent[a])
    return a;
  return parent[a] = Find(parent[a]);
}

void Union(int a, int b){
  int Pa = Find(a);
  int Pb = Find(b);

  if( Pa == Pb) return;
  if(Pb > Pa)
    parent[Pb] = Pa;
  else
    parent[Pa] = Pb;
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
        Union(i,j);
      }
    }
  }
  int First,Second;
  scanf("%d",&First);
  for(int i=1;i<M;i++){
    scanf("%d",&Second);
    if(Find(First) != Find(Second)){
      printf("NO");
      return 0;
    }
    First = Second;
  }
  printf("YES");
  return 0;
}
