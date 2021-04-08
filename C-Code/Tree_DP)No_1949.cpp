#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int arr[10001],dp[10001][2],visit[10001];
vector<int> V[10001],printN;

int dfs(int current, int ago, int visit){
  int &ans = dp[current][visit]; // 시간줄이는 포인트
  if(ans != -1) return ans;
  ans = 0;
  if(visit == 1) ans = arr[current];
  int size = V[current].size();
  for(int i=0;i<size;i++){
    int next = V[current][i];
    if(next == ago ) continue;
    if(visit){
      ans += dfs(next,current,0);
    }else{
      ans += max(dfs(next,current,0),dfs(next,current,1));
    }
  }
  return ans;
}

void makeN(int current, bool select){
  bool tmpselect = false;
  visit[current] =1;
  if(select == false && dp[current][1] >= dp[current][0]){
    printN.push_back(current);
    tmpselect = true;
  }
  int size = V[current].size();
  for(int i=0;i<size;i++){
    int next = V[current][i];
    if(!visit[next])
      makeN(next,tmpselect);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N,a,b;
  memset(dp,-1,sizeof(dp));
  cin>>N;
  for(int i=1;i<=N;i++)
    cin>>arr[i];
  for(int i=1;i<=N-1;i++){
    cin>>a>>b;
    V[a].push_back(b);
    V[b].push_back(a);
  }
  int Nsel = dfs(1,0,0);
  int Ysel = dfs(1,0,1);
  if(Nsel > Ysel){
    cout<<Nsel<<'\n';
    makeN(1,true);
  }else{
    cout<<Ysel<<'\n';
    makeN(1,false);
  }
  sort(printN.begin(),printN.end());
  for(int i=0;i<printN.size();i++){
    cout<<printN[i]<<' ';
  }
  return 0;
}
/*
값에 대한 ret을 하기 때문에 배열이 필요하지않다.

1. 현재 마을이 우수마을인지 아닌지
1-1. 우수마을이라면
	=> 연결된 다음마을은 절대 우수마을이 아니다.
		ans += dfs(다음마을, 0)
1-2. 우수마을이 아니라면
	=> 연결된 다음마을은 우수마을 or 우수마을이 아닐 수 있다.
		ans += max(dfs(다음마을, 1) +arr[다음마을], dfs(다음마을, 0))
2. 방문마을을 체크하면서 지나간다.
	check[current] = 1;


3. Tree이기 때문에 사이클이 없다. => 한마을에 대해 다른 두마을에서의 접근을 고민안해도된다.
ex) 1번마을 방문시 -> 2번 체크 x -> 3번 방문 -> 4번 방문x -> 5번 방문
 1 - 2 - 3 - 4 - 5	                   -> 6번 방문 -> 7번 방문x
     ㅣ 			      -> 6번 방문x -> 7번 방문
      6 - 7
*/
