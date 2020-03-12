#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> V;
int N,M,Max = 0;

void bs(int left,int right){
  long long mid;
  while(left<right){
    mid = (left+right)/2;
    long long val=0,tmp=0;
    for(int i=0;i<N;i++){
      tmp = V[i] - mid;
      if(tmp >0) val += tmp;
    }
    if(val<M){
      right = mid;
    }else if(val>=M){
      if (Max < mid) Max = mid;
      left = mid+1;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a;
  cin>>N>>M;
  for(int i=0;i<N;i++){
    cin>>a;
    V.push_back(a);
  }
  sort(V.begin(),V.end());
  bs(0,V[N-1]);
  cout<<Max;
  return 0;
}
