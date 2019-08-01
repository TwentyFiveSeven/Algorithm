#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
queue<pair<int,int>> Q;
vector<pair<int,int>> V[100001];
vector<pair<int,int>>::iterator iter;
bool check[100001];
int n;

int bfs(int child,int weightN){
  int i,childN=0,maxvalue=0,size =0;
  Q.push(make_pair(child,weightN));
  while(!Q.empty()){
    childN = Q.front().first;
    weightN = Q.front().second;
    Q.pop();
    for (iter = V[childN].begin(); iter != V[childN].end(); iter++){
      if(!check[(*iter).first]){
        // printf("check[%d]\n",(*iter).first);
        Q.push(make_pair((*iter).first,(*iter).second+weightN));
        if(weightN+(*iter).second>maxvalue) maxvalue = (*iter).second + weightN;
        check[(*iter).first] =1;
      }
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
    }
  }
  for(i=1;i<=n;i++){
    while(!V[i].empty()){
      check[i] = 1;
      inputA = V[i].back().first;
      inputB = V[i].back().second;
      check[inputA] = 1;
      value = bfs(inputA,inputB);
      V[i].pop_back();
      if(value>left){
        left = value;
      }
    }
    for(j=1;j<=n;j++){
      check[j] = 0;
    }
  }
  printf("%d",left);
  return 0;
}
