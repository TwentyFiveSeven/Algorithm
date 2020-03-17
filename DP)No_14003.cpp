#include<iostream>
#include<vector>
using namespace std;
int N, arr[1000001],dp[1000001];
vector<pair<int,int>> V,ans;

int Lower_bound(int End, int value){
  int start = 1;
  while(start < End){
    int mid = (start+End)/2;
    if(dp[mid] >= value){
      End = mid;
    }else
      start = mid+1;
  }
  return End;
}

void LIS(){
  V.push_back(make_pair(1,arr[1]));
  dp[1] = arr[1];
  int idx = 1;
  for(int i=2;i<=N;i++){
    if(dp[idx] < arr[i]){
      dp[++idx] = arr[i];
      V.push_back(make_pair(idx,arr[i]));
    }else{
      int next = Lower_bound(idx,arr[i]);
      dp[next] = arr[i];
      V.push_back(make_pair(next,arr[i]));
    }
  }
  printf("%d\n",idx);
  int find = idx,size = V.size();
  for(int i=size-1;i>=0;i--){
    if(find == V[i].first){
      dp[find] = V[i].second;
      find--;
    }
  }
  for(int i=find+1;i<=idx;i++){
    printf("%d ",dp[i]);
  }
}

int main(){
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d",&arr[i]);
  }
  LIS();
  return 0;
}
