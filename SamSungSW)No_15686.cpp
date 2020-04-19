#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,M,arr[50][50],Min = 2000000001,ans =2000000001;
long long Ret = 0;
vector<pair<int,int>> H,C;

int cal(vector<int> temp){
  int ret = 0;
  int Hsize = H.size();
  pair<int,int> T;
  for(int i=0;i<Hsize;i++){
    T.first = -1, T.second = 2000000001;
    int x = H[i].first;
    int y = H[i].second;
    for(int j=0;j<M;j++){
      int nx = C[temp[j]].first;
      int ny = C[temp[j]].second;
      int distance = abs(x-nx) + abs(y - ny);
      if(distance < T.second){
        T.first = temp[j];
        T.second = distance;
      }
    }
    ret += T.second;
  }
  return ret;
}

void solve(int start, int depth,vector<int> temp){
  if(depth == M){
    ans = min(ans,cal(temp));
    return;
  }else if(start>C.size()){
    return;
  }
  int size = C.size();
  for(int i=start;i<size;i++){
    temp.push_back(i);
    solve(i+1,depth+1,temp);
    temp.pop_back();
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> V;
  cin>>N>>M;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>arr[i][j];
      if(arr[i][j] == 1)
        H.push_back(make_pair(i,j));
      else if(arr[i][j] == 2)
        C.push_back(make_pair(i,j));
    }
  }
  solve(0,0,V);
  cout<<ans;
  return 0;
}
