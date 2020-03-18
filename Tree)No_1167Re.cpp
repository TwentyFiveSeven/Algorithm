#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
vector<pair<int,int>> V[100001],D;
int N,check[100001],Max =0,save = -1;

void dfs(int start){
  D.push_back(make_pair(start,0));
  while(!D.empty()){
    int start = D.back().first;
    int val = D.back().second;
    D.pop_back();
    if(check[start] == 1)continue;
    check[start] = 1;
    for(int i=0;i<V[start].size();i++){
      if(check[V[start][i].first] == 0){
        int value = val+V[start][i].second;
        if(value > Max){
          Max = value;
          save = V[start][i].first;
        }
        D.push_back(make_pair(V[start][i].first,value));
      }
    }
  }
}

int main(){
  int num,a,b;
  scanf("%d",&N);
  int T = N;
  while(T--){
    scanf("%d",&num);
    while(1){
      scanf("%d",&a);
      if(a == -1) break;
      scanf("%d",&b);
      V[num].push_back(make_pair(a,b));
    }
  }
  dfs(1);
  memset(check,0,sizeof(check));
  dfs(save);
  printf("%d",Max);
  return 0;
}
