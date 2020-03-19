#include<iostream>
using namespace std;
int in[100001],post[100001],in_loc[100001],N;

void solve(int Is, int Os,int length){
  if(length <= 0|| Is >N || Os > N) return;
  int root = post[Os+length-1];
  printf("%d ",root);
  int line = in_loc[root];
  int leftsize = line-Is;
  solve(Is,Os,leftsize);
  int rightsize = length - leftsize -1;
  solve(line+1,Os+leftsize,rightsize);
}

int main(){
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d",&in[i]);
    in_loc[in[i]] = i;
  }
  for(int i=1;i<=N;i++)
    scanf("%d",&post[i]);
  solve(1,1,N);
  return 0;
}
