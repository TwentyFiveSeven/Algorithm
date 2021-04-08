#include<iostream>
#include<vector>
using namespace std;
vector<int> V;
int arr[10001];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N,K,a;
  cin>>N>>K;
  for(int i=0;i<N;i++){
    cin>>a;
    V.push_back(a);
  }
  arr[0] = 1;
  for(int i =0;i<N;i++){
    for(int j=1;j<=K;j++){
      if(j>=V[i]){
        int temp = j-V[i];
        arr[j] += arr[temp];
      }
    }
  }
  cout<<arr[K];
  return 0;
}
