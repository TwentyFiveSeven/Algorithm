#include<iostream>
#include<map>
#include<math.h>
using namespace std;
int size = 0,count =0,ans=0;
typedef struct trie{
  int num=1;
  char c;
  map<char,trie*> children;

  void insert(string s, int depth){
    if(depth == size){
      trie* NewN = new trie;
      children.insert({'-',NewN});
      return;
    }
    map<char,trie*>::iterator iter;
    if((iter = children.find(s[depth])) == children.end()){
      trie* NewN = new trie;
      children.insert({s[depth],NewN});
      NewN->insert(s,depth+1);
    }else{
      iter->second->num++;
      iter->second->insert(s,depth+1);
    }
  }

  void Find(int depth){
    int Size = children.size();
    if(depth ==0){
      for(auto iter = children.begin();iter != children.end();iter++){
        ans += iter->second->num;
        iter->second->Find(depth+1);
      }
    }else if(Size == 1){
      auto iter = children.begin();
      iter->second->Find(depth + 1);
    }else if(Size > 1){
      for(auto iter = children.begin();iter != children.end();iter++){
        if(iter->first != '-')
          ans += iter->second->num;
        iter->second->Find(depth + 1);
      }
    }else{
      return;
    }
  }
}trie;

int main(){
  int N;
  string s;
  while(cin>>N){
    trie* root = new trie;
    for(int i=0;i<N;i++){
      cin>>s;
      size = s.size();
      root->insert(s,0);
    }
    root->Find(0);
    delete root;
    double res = (double)ans/(double)N;
    ans =0;
    res = round(res*100)/100;
    cout<<fixed;
    cout.precision(2);
    cout<<res<<'\n';
  }
  return 0;
}
