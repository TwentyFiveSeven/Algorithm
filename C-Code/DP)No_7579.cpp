#include<iostream>
#include<algorithm>
using namespace std;
int m[101],c[101],dp[10001];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N,M,sum=0;
  cin>>N>>M;
  for(int i=1;i<=N;i++)
    cin>>m[i];
  for(int i=1;i<=N;i++){
    cin>>c[i];
    sum += c[i];
  }
  for(int i=1;i<=N;i++){
    for(int j = sum; j>= c[i]; j--){
      dp[j] = max(dp[j], dp[j-c[i]]+m[i]);
    }
  }
  for(int i=1;i<=sum;i++){
    if(dp[i] >= M){
      cout<<i;
      break;
    }
  }
  return 0;
}
