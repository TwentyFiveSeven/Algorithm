#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,pair<int,int>>> V;
int par[10001];
int Find(int a){
  if(par[a] == a )
    return a;
  return par[a] = Find(par[a]);
}

int check(int a,int b){
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
  int K,E,a,b,c;
  cin>>K>>E;
  for(int i=0;i<K;i++) par[i] = i;
  for(int i=0;i<E;i++){
    cin>>a>>b>>c;
    V.push_back(make_pair(c,make_pair(a,b)));
  }
  sort(V.begin(),V.end());
  long long sum=0;
  int count = 0;
  for(int i=0;i<E;i++){
    if(count == K-1) break;
    if(check(V[i].second.first,V[i].second.second)){
      sum += V[i].first;
      count++;
    }
  }
  cout<<sum;
  return 0;
}
