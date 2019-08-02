#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
queue<pair<int,int>> Q;
vector<pair<int,int>> V[100001];
bool check[100001];
int n;

int bfs(){
  int i,j,childN=0,maxvalue=0,size =0,weightN=0,tmp=0;
  for(i=1;i<=n;i++){
    Q.push(make_pair(i,0));
    check[i] = true;
    while(!Q.empty()){
      childN = Q.front().first;
      weightN = Q.front().second;
      Q.pop();
        if(weightN>maxvalue){
          maxvalue = weightN;
        }
      for(j=0;j<V[childN].size();j++){
        tmp = V[childN][j].first;
        if(!check[tmp]){
          Q.push(make_pair(tmp,V[childN][j].second+weightN));
          check[tmp] = true;
        }
      }
    }
    for(j=1;j<=n;j++) check[j]=0;
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
      value = bfs();
  printf("%d",value);
  return 0;
}
