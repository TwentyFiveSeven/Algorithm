#include<iostream>
#include<vector>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
vector<pair<int,int>> V;
int N,W,dp[1002][1002],choose[1002][1002];

int dist(pair<int,int> a, pair<int,int> b){
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(int x,int y){
  int curr = max(x,y) +1;
  if(curr == W+2) return 0;
  int &ret = dp[x][y];
  if(dp[x][y] != -1) return ret;

  ret = solve(curr,y) + dist(V[x],V[curr]);
  int temp = solve(x,curr) + dist(V[y],V[curr]);
  if(temp < ret){
    ret = temp;
    choose[x][y] = 1;
  }
  return ret;
}

int main(){
  int a,b;
  scanf("%d %d",&N,&W);
  memset(dp,-1,sizeof(dp));
  V.push_back(make_pair(1,1));
  V.push_back(make_pair(N,N));
  for(int i=0;i<W;i++){
    scanf("%d %d",&a,&b);
    V.push_back(make_pair(a,b));
  }
  printf("%d\n",solve(0,1));
  for(int x=0,y=1;max(x,y)+1<W+2;){
    printf("%d\n",choose[x][y]+1);
    if(choose[x][y]) y = max(x,y) +1;
    else
      x = max(x,y)+1;
  }
  return 0;
}
