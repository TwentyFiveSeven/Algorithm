#include<iostream>
using namespace std;
int parent[1000001],N,M;

int Find(int a){
  if(parent[a] == a)
    return a;
  return Find(parent[a]);
}

void Union(int a, int b){
  int ap = Find(a);
  int bp = Find(b);
  if(ap == bp)
    return;
  else{
    if(ap < bp){
      parent[bp] = ap;
    }else{
      parent[ap] = bp;
    }
  }
}

int main(){
  int N,M,slc,a,b;
  scanf("%d %d",&N,&M);
  for(int i=0;i<=N;i++)
    parent[i] = i;
  for(int i=0;i<M;i++){
    scanf("%d %d %d",&slc,&a,&b);
    if(slc){
      int ap = Find(a);
      int bp = Find(b);
      if(ap == bp)
        printf("YES\n");
      else
        printf("NO\n");
    }else{
      Union(a,b);
    }
  }
}
