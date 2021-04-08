#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
vector<pair<int,pair<int,int>>> V;
vector<pair<pair<int,int>,pair<int,int>>> tmp;

bool cmp1(pair<pair<int,int>,pair<int,int>> a, pair<pair<int,int>,pair<int,int>> b){
  return a.first.first < b.first.first;
}
bool cmp2(pair<pair<int,int>,pair<int,int>> a, pair<pair<int,int>,pair<int,int>> b){
  return a.second.first < b.second.first;
}
bool cmp3(pair<pair<int,int>,pair<int,int>> a, pair<pair<int,int>,pair<int,int>> b){
  return a.second.second < b.second.second;
}
int par[100001];
int Find(int a){
  if(par[a] == a)
    return a;
  return par[a] = Find(par[a]);
}

int check(int a,int b){
  int pa = Find(a);
  int pb = Find(b);
  if(pa == pb) return 0;
  if(pa > pb)
    par[pb] = pa;
  else
    par[pa] = pb;
  return 1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N,x,y,z;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>x>>y>>z;
    tmp.push_back(make_pair(make_pair(x,i),make_pair(y,z)));
    par[i] = i;
  }
  sort(tmp.begin(),tmp.end(),cmp1);
  for(int i=0;i<N-1;i++) V.push_back(make_pair(abs(tmp[i+1].first.first-tmp[i].first.first),make_pair(tmp[i+1].first.second,tmp[i].first.second)));
  sort(tmp.begin(),tmp.end(),cmp2);
  for(int i=0;i<N-1;i++) V.push_back(make_pair(abs(tmp[i+1].second.first-tmp[i].second.first),make_pair(tmp[i+1].first.second,tmp[i].first.second)));
  sort(tmp.begin(),tmp.end(),cmp3);
  for(int i=0;i<N-1;i++) V.push_back(make_pair(abs(tmp[i+1].second.second-tmp[i].second.second),make_pair(tmp[i+1].first.second,tmp[i].first.second)));

  sort(V.begin(),V.end());
  int size = V.size(),count =0;
  long long sum =0;
  for(int i=0; i<size;i++){
    if(count == N-1) break;
    if(check(V[i].second.first,V[i].second.second)){
      sum += V[i].first;
      count++;
    }
  }
  cout<<sum;
  return 0;
}
