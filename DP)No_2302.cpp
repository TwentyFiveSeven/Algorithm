#include<iostream>
#include<vector>
using namespace std;
vector<int> V;
int arr[10001];
int main(){
  int T,N,temp,M;
  arr[0] = 1;
  cin>>T;
  while(T--){
    cin>>N;
    for(int i=0;i<N;i++){
      cin>>temp;
      V.push_back(temp);
    }
    cin>>M;
    for(int i=0;i<N;i++){
      for(int j=V[i];j<=M;j++){
        arr[j] += arr[j-V[i]];
      }
    }
    cout<<arr[M]<<'\n';
    for(int i=1;i<=M;i++)
      arr[i] = 0;
    V.clear();
  }
  return 0;
}
