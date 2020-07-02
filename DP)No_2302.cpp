#include<iostream>
#include<vector>
using namespace std;
vector<int> V;
int arr[41], dp[41];
int main(){
  int N,temp,M;
  dp[0] = 1;
  dp[1] = 1;
  cin>>N>>M;
  for(int i=0;i<M;i++){
    cin>>temp;
    arr[temp] = 1;
    if(temp+1 <=N)
      arr[temp+1] = 2;
    if(temp+2 <=N)
      arr[temp+2] = 3;
  }
  for(int i=2;i<=N;i++){
    if(arr[i] ==1 || arr[i] ==2){
      dp[i] = dp[i-1];
    }else if(arr[i] == 3){
      dp[i] = dp[i-1]*2;
    }else{
      dp[i] = dp[i-1] + dp[i-2];
    }
  }
  // for(int i=1;i<=N;i++){
  //   cout<<dp[i]<<' ';
  // }
  // cout<<'\n';
  cout<<dp[N];
  return 0;
}
