#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> V,ans;
int num,N,M;

int l_bound(int left, int right){
  int Max = 0;
  while(left<right){
    int mid = (left+right)/2;
    if(V[mid]<num){
      left = mid+1;
    }else{
      right = mid;
    }
  }
  return left;
}

int r_bound(int left, int right){
  while(left<right){
    int mid = (left+right)/2;
    if(V[mid]<=num){
      left = mid+1;
    }else{
      right = mid;
    }
  }
  if(V[right]== num) right++;
  return right;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a,left,right;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>a;
    V.push_back(a);
  }
  sort(V.begin(),V.end());
  cin>>M;
  for(int i=0;i<M;i++){
    cin>>num;
    left = 0,right = N-1;
    left = l_bound(left,right);
    right = r_bound(left,right);
    cout<<right-left<<" ";
  }
  return 0;
}
