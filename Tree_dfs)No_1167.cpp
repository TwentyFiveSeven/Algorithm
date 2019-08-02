#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> V[100001];
bool check[100001];
int n,ans;

int dfs(int root){  //앞에 방법으로 while문으로 돌리게되면 반복한 것을 다시 이용하기 떄문에 기하급수적으로 반복 수가 커진다.
  int i,j,first=0,second=0,value=0; //이 방법은 dfs지만 check를 통해서 반복되는 경로는 되풀이되지않는다.
  check[root] = true;
  for(auto child : V[root]){
    if(check[child.first]) continue;
    check[child.first] = true;
    value = dfs(child.first) + child.second;  //이 재귀적인 표현을 통해서 subtree에서 발생하는 가장 큰 경로도 확인
    if(value > first){        //만일 subtree에서 발생한다면 체크후에 다음 탐색을 진행한다.
      second = first;
      first = value;
    }else if(value > second)
      second = value;
  }
  ans = max(ans,first+second);  //ans를 전역변수로 사용하여 지속적으로 최대값을 저장.
  return first; //return 값은 main으로의 return이 아닌 재귀적인 return 값이므로 가장 큰 값만을 return 한다.
}

int main(){
  int i,j,parent=0,child=0,Nweight=0;
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
  dfs(1);
  printf("%d",ans);
  return 0;
}
