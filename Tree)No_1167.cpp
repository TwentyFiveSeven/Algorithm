#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
queue<pair<int,int>> Q;
vector<pair<int,int>> V[100001];
bool check[100001];
vector<pair<int,int>>::iterator iter;
int n;

int bfs(int child){
  int i,childN=0,maxvalue=0,size =0,weightN=0;
  Q.push(make_pair(child,0));
  while(!Q.empty()){
    childN = Q.front().first;
    weightN = Q.front().second;
    Q.pop();
      if(weightN>maxvalue){
        maxvalue = weightN;
      }
    for (iter = V[childN].begin(); iter != V[childN].end(); iter++){
      if(check[(*iter).first]) continue;
      Q.push(make_pair((*iter).first,(*iter).second+weightN));
      check[(*iter).first] = 1;
    }
  }
  return maxvalue;
}

int main(){
  int i,j,parent=0,child=0,Nweight=0,left=0,right=0,maxvalue=0,value=0,inputA=0,inputB=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&parent);
    while(1){
      scanf("%d",&child);
      if(child==-1) break;
      scanf("%d",&Nweight);
      V[parent].push_back(make_pair(child,Nweight));
      if(child<parent){
        pair<int,int> p = make_pair(parent,Nweight);
        V[child].erase(p);
      }
    }
  }

  for(i=n;i>=1;i--){
    left =0;right=0;
    while(!V[i].empty()){ 
      check[i] = 1;
      value = bfs(i);
      V[i].pop_back();
      if(value>left){
        right = left;
        left = value;
      }
      else if(value>right) right = value;
    }
    for(j=1;j<=n;j++){
      check[j]=0;
    }
    if((left+right)>maxvalue) maxvalue = left+right;
  }
  printf("%d",maxvalue);
  return 0;
}
