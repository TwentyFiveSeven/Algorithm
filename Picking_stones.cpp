#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
bool Player = true;
vector<int> input,K,temp;
int N,M,DEPTH=0,VISIT_NODE=0;

typedef struct node{
  int num = 0;
  vector<pair<int,pair<double,node*>>> children;

  void insert(vector<int> S){
    int size = S.size();
    if(size == 0) return;
    for(int i=0;i<size;i++){
      node* NewN = new node;
      NewN->num = S[i];
      children.push_back(make_pair(S[i],make_pair(0.0,NewN)));
    }
  }

  pair<int,double> AB_pruning(int NodeValue,double NodeEvalu,double alpha, double beta,int dep,bool TURN){
    int ANS_NODE = -1;
    if(NodeValue == 0)
      return make_pair(num,NodeEvalu);
    if(NodeValue == -1){
      DEPTH = max(DEPTH,dep);
      return make_pair(num,NodeEvalu);
    }
    if(TURN){  //Max
      int size = children.size();
      for(int i=0;i<size;i++){
        int val = children[i].first;
        if(val != 0)
          VISIT_NODE++;
        pair<int,double> T = children[i].second.second->AB_pruning(val,children[i].second.first,alpha,beta,dep+1,false);
        DEPTH = max(DEPTH,dep);
        if(i == 0) ANS_NODE = children[i].first;
        if(T.second > alpha){
          ANS_NODE = children[i].first;
          alpha = T.second;
        }
        if(beta <= alpha)
          break;
      }
      return make_pair(ANS_NODE,alpha);
    }else{  //MIN
      int size = children.size();
      for(int i=0;i<size;i++){
        int val = children[i].first;
        if(val != 0)
          VISIT_NODE++;
        pair<int,double> T = children[i].second.second->AB_pruning(val,children[i].second.first,alpha,beta,dep+1,true);
        DEPTH = max(DEPTH,dep);
        if(i == 0) ANS_NODE = children[i].first;
        if(T.second < beta){
          ANS_NODE = children[i].first;
          beta = T.second;
        }
        if(beta <= alpha)
          break;
      }
      return make_pair(ANS_NODE,beta);
    }
  }
}node;

int arr_empty(vector<int> arr){
  for(int i=1;i<=N;i++) if(arr[i] == 0) return 0;
  return 1;
}

void plus_Node(vector<int> I, node* N,vector<int> arr,int i){
  double val = 1;
  if(Player) val = -val;
  if(K.size() == 0){
    if(!arr_empty(arr)){
      node* NewN = new node;
      NewN->num = -1;
      N->children[i].second.second->children.push_back(make_pair(-1,make_pair(val,NewN)));
    }else{
      node* NewN = new node;
      NewN->num = 0;
      N->children[i].second.second->children.push_back(make_pair(0,make_pair(val,NewN)));
    }
  }else
    N->children[i].second.second->insert(I);
}

vector<int> makeRest(int num,vector<int> arr){
  vector<int> ret;
  if(num ==0){
    for(int i=1;i<N/2+N%2;i++){
      if(i%2)
        ret.push_back(i);
    }
    return ret;
  }
  for(int i=1;i<num;i++)
    if(!arr[i])
      if(num%i==0){
        ret.push_back(i);
      }
  for(int i=2;i<=N;i++){
    int val = num*i;
    if(val >N) break;
    if(!arr[val])
      ret.push_back(val);
  }
  return ret;
}

void Make_Tree(node* N,vector<int> arr){
  int size = N->children.size();
  if(size == 0) return;
  for(int i=0;i<size;i++){
    int val = N->children[i].first;
    if(val == -1) return;
    arr[val] = 1;
    Player = !Player;
    K = makeRest(val,arr);
    plus_Node(K,N,arr,i);
    K.clear();
    Make_Tree(N->children[i].second.second,arr);
    arr[val] = 0;
    Player = !Player;
  }
}

int main(){
  string s;
  cin>>N>>M;
  int al = N+1,a,val;
  vector<int> arr(al,0);
  for(int i=0;i<M;i++){
    cin>>a;
    arr[a] = 1;
    input.push_back(a);
  }
  if(M%2)
    Player = !Player;
  if(input.size() == 0)
    val = 0;
  else
    val = input[input.size()-1];
  vector<int> R = makeRest(val,arr);
  node* root = new node;
  root->insert(R);
  Make_Tree(root,arr);
  // cout<<root->children[0].first<<'\n';
  // cout<<root->children[0].second.second->children[0].first<<'\n';
  // cout<<root->children[0].second.second->children[0].second.second->children[0].second.first<<'\n';
  if(M%2)
    Player = false;
  else
    Player = true;
  pair<int,double> ANS = root->AB_pruning(-2,0.0,-1.0,1.0,-1,Player);
  cout<<"Best Move : "<<ANS.first<<'\n';
  cout<<"Calculated Value : "<<ANS.second<<'\n';
  cout<<"Number of Visited Nodes : "<<VISIT_NODE<<'\n';
  cout<<"Max Depth : "<<DEPTH;
  return 0;
}
