#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
queue<pair<int,int>> Q;
vector<pair<int,int>> V[10001];
vector<pair<int,int>>::iterator iter;
int n;

int bfs(int child,int weightN){ //bfs를 통해서 입력된 값에서 리프노드까지 나올 수 있는 모든 값을 return 한다.
  int i,childN=0,maxvalue=0,size =0;
  Q.push(make_pair(child,weightN));
  while(!Q.empty()){
    childN = Q.front().first;
    weightN = Q.front().second;
    Q.pop();
    if(V[childN].empty()){
      if(weightN>maxvalue){
        maxvalue = weightN;
      }
      continue;
    }
    for (iter = V[childN].begin(); iter != V[childN].end(); iter++){
      Q.push(make_pair((*iter).first,(*iter).second+weightN));
    }
  }
  return maxvalue;
}

int main(){
  int i,j,parent=0,child=0,Nweight=0,left=0,right=0,maxvalue=0,value=0,inputA=0,inputB=0;
  scanf("%d",&n);
  for(i=1;i<n;i++){
    scanf("%d %d %d",&parent,&child,&Nweight);
    V[parent].push_back(make_pair(child,Nweight));  //vector<pair<int,int>>배열을 통해서 int 세개의 값을 잘 저장한다.
  }
  for(i=1;i<=n;i++){  //자식들이 있는 노드들을 확인한다.
    left =0;right=0;
    while(!V[i].empty()){ //자식이 있다면 현재 위치에서 그 자식들 중에 가장 큰 경로 두개를 탐색한다.
      inputA = V[i].back().first;
      inputB = V[i].back().second;
      value = bfs(inputA,inputB);
      V[i].pop_back();
      if(value>left){
        right = left;
        left = value;
      }
      else if(value>right) right = value;
    }
    if((left+right)>maxvalue) maxvalue = left+right;
  }
  printf("%d",maxvalue);
  return 0;
}
