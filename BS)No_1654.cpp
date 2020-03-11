#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
vector<long long> V;
long long K,N,a,Max = 0;

void bs(long long left, long long right){
  while(left<=right){
    long long mid = (left+right)/2;
    long long count = 0;
    for(int i=0;i<K;i++){
      count+=V[i]/mid;
    }
    if(count>=N){
      if(Max < mid) Max = mid;
      left = mid+1;
    }else{
      right = mid-1;
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>K>>N;
  for(int i=0;i<K;i++){
    cin>>a;
    V.push_back(a);
  }
  sort(V.begin(),V.end());
  bs(1,V[K-1]);
  cout<<Max;
  return 0;
}
