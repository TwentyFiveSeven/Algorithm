#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int ansC=0;
vector<string> S ={"frodo","front","frost","frozen","frame","kakao"};
vector<string> Queries ={"fro??","????o","fr???","frame","pro?"};

typedef struct node{
  struct node* alpha[26];
  int end;
  int count =0;
}node;

node* newNode(){//init
  node* newN = (node *)malloc(sizeof(node));
  newN->end =0;
  for(int i=0; i<26;i++) newN->alpha[i] = 0;
  return newN;
}

void insert(node* root, string str){
  int size = str.size();
  node* now = root;

  for(int i=0;i<size;i++){
    if(!now->alpha[str[i]-'a']) now->alpha[str[i]-'a'] = newNode();
    now = now->alpha[str[i]-'a'];
  }
  now->end = 1;
}

void recur(node* root,string s, int depth,int limit){
  printf("limit : %d, depth : %d\n",limit,depth);
  if(depth==limit&&root->end ==1){
    ansC++;
    return;
  }
  for(int i=0;i<26;i++){
    if(root->alpha[i]) recur(root->alpha[i],s,depth+1,limit);
  }
}

int find(node* root,string s){
  int ret=0,depth=0,i;
  node* Nroot = root;
  int j,size = s.size();
  for(i=0;i<size;i++){
    if(s[i]=='?') break;
    if(!Nroot->alpha[s[i]-'a']) {
      return 0;
    }
    Nroot = Nroot->alpha[s[i]-'a'];
    depth++;
  }
  node* now = Nroot;
  ansC =0;
  recur(now,s,depth,size);
  return ansC;
}

int main(){
  vector<int> answer;
  int i,size = S.size(),Qsize = Queries.size();
  node* Froot = newNode();
  node* Proot = newNode();
  for(i=0;i<size;i++) insert(Froot,S[i]);

  for(i=0;i<size;i++) {
    reverse(S[i].begin(),S[i].end());
    insert(Proot,S[i]);
    // reverse(S[i].begin(),S[i].end());
  }

  for(i=0;i<Qsize;i++){
    if(Queries[i][0] == '?'){
      // string rever =
      reverse(Queries[i].begin(),Queries[i].end());
      answer.push_back(find(Proot,Queries[i]));
    }else{
      answer.push_back(find(Froot,Queries[i]));
    }
  }

  for(i=0;i<answer.size();i++){
    printf("%d ",answer[i]);
  }
  return 0;
}
