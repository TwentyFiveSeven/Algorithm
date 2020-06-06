#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<string,pair<int,int>> M;
vector<pair<string,pair<int,int>>> V;

bool cmp(pair<string,pair<int,int>> a, pair<string,pair<int,int>> b){
  if(a.second.first == b.second.first){
    if(a.second.second == b.second.second)
      return a.first < b.first;
    else
      return a.second.second > b.second.second;
  }else
    return a.second.first > b.second.first;
}

int main(){
  string temp,s;
  int N;
  getline(cin,temp);
  N = atoi(temp.c_str());
  int size = N*(N-1);
  for(int i=0;i<size;i++){ // a 3 b 1
    getline(cin,s);
    int fs = s.find(' ');
    int ss = s.find(' ',fs+1);
    int ts = s.find(' ',ss+1);
    string s1 = s.substr(0,fs);
    int val1 = atoi(s.substr(fs+1,ss-(fs+1)).c_str());
    string s2 = s.substr(ss+1,ts-(ss+1));
    int val2 = atoi(s.substr(ts+1,s.size()-(ts+1)).c_str());
    if(M.count(s1)== 0){
      M[s1].first = 0;
      M[s1].second = 0;
    }
    if(M.count(s2) == 0){
      M[s2].first= 0;
      M[s2].second = 0;
    }
    if( val1 > val2){
      M[s1].first++;
      M[s1].second += val1 - val2;
      M[s2].second += val2 - val1;
    }else{
      M[s2].first++;
      M[s2].second += val2 - val1;
      M[s1].second += val1 - val2;
    }
  }
  for(auto iter = M.begin(); iter != M.end(); iter++){
    V.push_back(make_pair(iter->first,make_pair(iter->second.first,iter->second.second)));
  }
  sort(V.begin(),V.end(),cmp);
  for(int i=0;i<V.size();i++){
    cout<<V[i].first<<' '<<V[i].second.first<<' '<<V[i].second.second<<'\n';
  }
  return 0;
}
