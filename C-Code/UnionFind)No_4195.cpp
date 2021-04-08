#include<iostream>
#include<map>
using namespace std;
map<string,pair<string,int>> M;
int T,F;

string Find(string s){
  auto temp = M.find(s);
  if(temp->second.first == s)
    return s;
  return Find(temp->second.first);
}

int Comp(string s, string f){
  if(s.size() == f.size()){
    if(s > f)
      return 0;
    return 1;
  }else{
    if(s.size() > f.size())
      return 0;
    return 1;
  }
}

int main(){
  string f,s;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>T;
  while(T--){
    cin>>F;
    for(int i=0;i<F;i++){
      cin>>f>>s;
      if(M.count(s) == 0)
        M.insert(make_pair(s,make_pair(s,1)));
      if(M.count(f) == 0)
        M.insert(make_pair(f,make_pair(f,1)));
      string sp = Find(s);
      string fp = Find(f);
      if( sp == fp){
        cout<<M[sp].second<<'\n';
        continue;
      }
      if(Comp(sp,fp)){//f > s
        M[fp].second += M[sp].second;
        M[sp].first = M[fp].first;
        cout<<M[fp].second<<'\n';
      }else{
        M[sp].second += M[fp].second;
        M[fp].first = M[sp].first;
        cout<<M[sp].second<<'\n';
      }
    }
    M.clear();
  }
  return 0;
}
