#include<iostream>
using namespace std;
long long arr[68];
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T,N;
  cin>>T;
  arr[0] = 1,arr[1] = 1,arr[2] = 2,arr[3] = 4;
  for(int i=4;i<=67;i++){
    arr[i] = arr[i-4]+arr[i-3]+arr[i-2]+arr[i-1];
  }
  while(T--){
    cin>>N;
    cout<<arr[N]<<'\n';
  }
  return 0;
}
