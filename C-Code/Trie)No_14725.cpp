#include<iostream>
#include<map>
#include<vector>
using namespace std;

typedef struct node{
  map<string,node*> children;
  void insert(vector<string> S, int idx){
    if(idx == S.size()) return;
    map<string,node*>::iterator iter;
    if((iter = children.find(S[idx])) == children.end()){
      node* NewN = new node;
      children.insert({S[idx],NewN});
      NewN->insert(S,idx+1);
    }else{
      iter->second->insert(S,idx+1);
    }
  }

  void Find(int level){
    int size = children.size();
    if(size == 0) return;
    for(auto iter = children.begin();iter!=children.end();iter++){
      for(int i=0;i<level;i++) cout<<"--";
      cout<<iter->first<<'\n';
      iter->second->Find(level+1);
    }
  }
}node;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N,M;
  node* root = new node;
  string s;
  vector<string> tmp;
  cin>>N;
  while(N--){
    cin>>M;
    for(int i=0;i<M;i++){
      cin>>s;
      tmp.push_back(s);
    }
    root->insert(tmp,0);
    tmp.clear();
  }
  root->Find(0);
  return 0;
}
