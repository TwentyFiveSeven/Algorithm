#include<iostream>

using namespace std;
int N,M,map[1025][1025],dp[1025][1025];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a,b,c,d;
  cin>>N>>M;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      cin>>map[i][j];
    }
  }
  for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
      dp[i][j] = map[i][j] + dp[i][j-1];
  for(int i=0;i<M;i++){
    int sum = 0;
    cin>>a>>b>>c>>d;
    for(int j=a;j<=c;j++)
      sum += dp[j][d] - dp[j][b-1];
    cout<<sum<<'\n';
  }
  return 0;
}
