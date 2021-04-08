#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
using namespace std;

typedef struct node node;
int arr_empty(vector<int> arr);
void plus_Node(vector<int> I, node* N,vector<int> arr,int i);
vector<int> makeRest(int num,vector<int> arr);
void Make_Tree(node* N,vector<int> arr);
vector<int> input_Stone(vector<int> &arr,char* argv[],int Limit);
int check(int num);

bool Player = true;
vector<int> input,K,temp;
int Num,M,DEPTH=0,VISIT_NODE=0;

typedef struct node{
  int num = -2;
  double EvaluationV = 0.0;
  vector<node*> children;

  void insert(vector<int> S){
    int size = S.size();
    if(size == 0) return;
    for(int i=0;i<size;i++){
      node* NewN = new node;
      NewN->num = S[i];
      children.push_back(NewN);
    }
  }

  pair<int,double> AB_pruning(double alpha, double beta,int dep,bool TURN){
    int ANS_NODE = -1;
    if(num == 0)
      return make_pair(num,EvaluationV);
    if(num == -1){
      DEPTH = max(DEPTH,dep);
      return make_pair(num,EvaluationV);
    }
    if(TURN){  //Max
      int size = children.size();
      for(int i=0;i<size;i++){
        int val = children[i]->num;
        if(val != 0)
          VISIT_NODE++;
        pair<int,double> T = children[i]->AB_pruning(alpha,beta,dep+1,false);
        DEPTH = max(DEPTH,dep);
        if(i == 0) ANS_NODE = children[i]->num;
        if(T.second > alpha){
          ANS_NODE = children[i]->num;
          alpha = T.second;
        }
        if(beta <= alpha)
          break;
      }
      return make_pair(ANS_NODE,alpha);
    }else{  //MIN
      int size = children.size();
      for(int i=0;i<size;i++){
        int val = children[i]->num;
        if(val != 0)
          VISIT_NODE++;
        pair<int,double> T = children[i]->AB_pruning(alpha,beta,dep+1,true);
        DEPTH = max(DEPTH,dep);
        if(i == 0) ANS_NODE = children[i]->num;
        if(T.second < beta){
          ANS_NODE = children[i]->num;
          beta = T.second;
        }
        if(beta <= alpha)
          break;
      }
      return make_pair(ANS_NODE,beta);
    }
  }
}node;

int main(int args, char* argv[]){
  string s;
  node* root = new node;
  Num = atoi(argv[1]);
  M = atoi(argv[2]);
  int al = Num+1,val,Limit = Num/2+Num%2;
  vector<int> arr(al,0);
  input = input_Stone(arr,argv,Limit);
  if(input.size()==1 && input[0] == -400)
    return 0;
  M%2 ? Player = !Player : Player;
  input.size() == 0 ? val = 0 : val = input[input.size()-1];
  vector<int> R = makeRest(val,arr);
  root->insert(R);
  Make_Tree(root,arr);
  M%2 ? Player = false : Player = true;
  pair<int,double> ANS = root->AB_pruning(INT_MIN,INT_MAX,-1,Player);

  cout << fixed;
  cout.precision(1);
  cout<<"Best Move : "<<ANS.first<<'\n';
  cout<<"Calculated Value : "<<ANS.second<<'\n';
  cout<<"Number of Visited Nodes : "<<VISIT_NODE<<'\n';
  cout<<"Max Depth : "<<DEPTH;
  return 0;
}


int arr_empty(vector<int> arr){
  for(int i=1;i<=Num;i++) if(arr[i] == 0) return 0;
  return 1;
}

void plus_Node(vector<int> I, node* N,vector<int> arr,int i){
  double val = 1;
  if(Player) val = -val;
  if(I.size() == 0){
    if(!arr_empty(arr)){
      node* NewN = new node;
      NewN->num = -1;
      NewN->EvaluationV = val;
      N->children[i]->children.push_back(NewN);
    }else{
      node* NewN = new node;
      NewN->num = 0;
      NewN->EvaluationV = val;
      N->children[i]->children.push_back(NewN);
    }
  }else
    N->children[i]->insert(I);
}

vector<int> makeRest(int num,vector<int> arr){
  vector<int> ret;
  if(num ==0){
    for(int i=1;i<Num/2+Num%2;i++){
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
  for(int i=2;i<=Num;i++){
    int val = num*i;
    if(val >Num) break;
    if(!arr[val])
      ret.push_back(val);
  }
  return ret;
}

void Make_Tree(node* N,vector<int> arr){
  int size = N->children.size();
  if(size == 0) return;
  for(int i=0;i<size;i++){
    int val = N->children[i]->num;
    if(val == -1 || val == 0) return;
    arr[val] = 1;
    Player = !Player;
    K = makeRest(val,arr);
    plus_Node(K,N,arr,i);
    K.clear();
    Make_Tree(N->children[i],arr);
    arr[val] = 0;
    Player = !Player;
  }
}

vector<int> input_Stone(vector<int> &arr,char* argv[],int Limit){
  vector<int> ret;
  int a;
  for(int i=0;i<M;i++){
    a = atoi(argv[3+i]);
    if(i==0 && a >=Limit){
      cout<<"The first player must choose an odd stone smaller than N/2\nEnd The Game";
      ret.push_back(-400);
      return ret;
    }
    arr[a] = 1;
    ret.push_back(a);
  }
  return ret;
}

int check(int num){
  int size = sqrt(num);
  for(int i=2;i<=size;i++){
    if(num%i ==0) return 0;
  }
  return 1;
}
