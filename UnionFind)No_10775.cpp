#include<iostream>
using namespace std;
int G,P,parent[100001],ans=0;

int find(int x){
  if(parent[x] == x)
    return x;
  return parent[x] = find(parent[x]);
}

int main(){
  int gate,flag = 0;
  scanf("%d %d",&G,&P);
  for(int i=1;i<=G;i++) parent[i] = i;
  for(int i=1;i<=P;i++){
    scanf("%d",&gate);
    int val = find(gate);
    if(val == 0 || flag == 1 ) {
      flag = 1;
      continue;
    }
    ans++;
    parent[val] = val-1;
  }
  printf("%d\n",ans);
  return 0;
}
