#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>> V;
int dp[502][502];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N,r,c;
  cin>>N;
  for(int i=1;i<=N;i++){
    cin>>r>>c;
    V.push_back(make_pair(r,c));
  }
  for(int i = N-1;i>=1;i--){
    for(int j = i+1;j<=N;j++){
      dp[i][j] = 2000000001;
      for(int k = i;k<j;k++){
        int val = dp[i][k] + dp[k+1][j];
        int mul =1;
        if(i == k ){
          mul = V[i-1].first*V[k].first*V[j-1].second;
        }else{
          mul =V[i-1].first*V[k-1].second*V[j-1].second;
        }
        dp[i][j] = min(dp[i][j],val+mul);
      }
    }
  }
  cout<<dp[1][N];
  return 0;
}
