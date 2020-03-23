#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int N,M,par[1001],check[1001][1001];
vector<pair<int,int>> tmp;
vector<pair<double,pair<int,int>>> V;

int Find(int a){
  if(par[a] == a)
    return a;
  return par[a] = Find(par[a]);
}

int solve(int a,int b){
  int pa = Find(a);
  int pb = Find(b);
  if(pa == pb) return 0;
  if(pa > pb){
    par[pa] = pb;
  }else
    par[pb] = pa;
  return 1;
}

int main(){
  int count = 0,a,b;
  double sum =0;
  scanf("%d %d",&N,&M);
  for(int i=0;i<N;i++){
    scanf("%d %d",&a,&b);
    tmp.push_back(make_pair(a,b));
    par[i] = i;
  }
  for(int i=0;i<M;i++){
    scanf("%d %d",&a,&b);
    if(solve(a-1,b-1)&&!check[a-1][b-1]){
      check[a-1][b-1] = check[b-1][a-1] = 1;
      count++;
    }
  }
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(check[i][j]) continue;
      double val = sqrt(pow(tmp[i].first-tmp[j].first,2) + pow(tmp[i].second-tmp[j].second,2));
      V.push_back(make_pair(val,make_pair(i,j)));
    }
  }
  sort(V.begin(),V.end());
  int size= V.size();
  for(int i=0;i<size;i++){
    if(count == N-1) break;
    if(solve(V[i].second.first,V[i].second.second)){
      count++;
      sum += V[i].first;
    }
  }
  printf("%.2lf",sum);
  return 0;
}
