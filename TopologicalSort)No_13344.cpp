#include<iostream>
#include<vector>
using namespace std;
int N,M,check[50001],p[50001];
vector<int> V[50001];
vector<pair<int,int>> temp;

int FindCycle(int now){
  if(check[now]){
    if(check[now] == -1)
      return 1;
    return 0;
  }
  check[now] = -1;
  int size = V[now].size();
  for(int i=0;i<size;i++){
    if(FindCycle(V[now][i]))
      return 1;
  }
  check[now] = 1;
  return 0;
}

int Find(int a){
  if(p[a] == a)
  return a;
  return p[a] = Find(p[a]);
}

void Union(int a,int b){
  int pa = Find(a);
  int pb = Find(b);
  if( pa == pb)
    return;
  if(pa > pb)
    p[pa] = pb;
  else
    p[pb] = pa;
}

int main(){
  int a,b;
  char tmp,c;
  cin>>N>>M;
  for(int i=0;i<N;i++) p[i] = i;
  for(int i=0;i<M;i++){
    cin>>a>>c>>b;
    if(c == '=')
      Union(a,b);
    else
      temp.push_back(make_pair(a,b));
  }
  int size = temp.size();
  for(int i=0;i<size;i++){
    int pa = Find(temp[i].first);
    int pb = Find(temp[i].second);
    V[pa].push_back(pb);
  }
  for(int i=0;i<N;i++){
    if(FindCycle(i)){
      cout<<"inconsistent";
      return 0;
    }
  }
  cout<<"consistent";
  return 0;
}
