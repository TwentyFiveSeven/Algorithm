#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

queue<int> Q;
vector<int> V[32001];
vector<int> ans;
int check[32001];
  //위상정렬은 가리킴받지않는 값이 가리키는 선들을 제거해나가면서 모든 선을 방문할 때 까지 진행한다.
int main(){
  int i,j,N,M,B,S,temp,count=0,value;;
  scanf("%d %d",&N,&M);
  for(i=0;i<N;i++) V[i].push_back(0); //i로 들어오는 수(i보다 작은 수)가 몇개 있는지 체크하는 공간.
  for(i=0;i<M;i++){
    scanf("%d %d",&B,&S);
    V[B-1][0]++;  // S라는 B보다 작은 값이 있으니까 작은 값에 count 한
    V[S-1].push_back(B-1);  // S보다 큰값 ( S가 가리키는 값)을 vector에 넣어준다.
  }
  for(i=0;i<N;i++)
  if(!check[i]&&V[i][0] == 0) { //가장 먼저 작은 값이 없는 값들을 Q에 넣는다.(가리킴 당하는 것이 없는 값)
      Q.push(i);
      check[i] = 1;
    }
  while(1){
    if(Q.empty()) break;
    temp = Q.front();
    Q.pop();
    while(V[temp].size()!=1){ //vector의 첫 값은 카운터용이므로 pop하지않는다.
      value = V[temp].back(); //temp보다 큰 값
      V[value][0]--;  //큰 값을 가리키는 선을 제거한다.
      if(!check[value]&&V[value][0] == 0){  //만약 큰 값이 가리킴 당하는 값이 없다면 Q에 push
        Q.push(value);
        check[value] = 1;
      }
      V[temp].pop_back(); //큰 값을 제거하고 다른 큰 값을 탐색.
    }
    ans.push_back(temp+1);  //나간 순서대로 저장.
  }
  reverse(ans.begin(),ans.end()); //반대로 뒤집는다.
  for(i=0;i<ans.size();i++) printf("%d ",ans[i]);
  return 0;
}
