#include<iostream>
#include<queue>
#include<set>
using namespace std;
queue<int> Q;
set<int> s;
int arr[101],check[1001];
int main(){
  int N,S,M;
  int Max=-1;
  cin>>N>>S>>M;
  for(int i=0;i<N;i++)
    cin>>arr[i];
  Q.push(S);
  for(int i=0;i<N;i++){
    int size = Q.size();
    for(int j=0;j<size;j++){
      int temp = Q.front();
      Q.pop();
      int Plus = temp+arr[i];
      int Minu = temp-arr[i];
      if(Plus<=M&& Plus>-1&&!s.count(Plus)){
        Q.push(Plus);
        s.insert(Plus);
      }
      if(Minu<=M&&Minu>-1&&!s.count(Minu)){
        Q.push(Minu);
        s.insert(Minu);
      }
    }
    s.clear();
  }
  while(!Q.empty()){
    Max = max(Max,Q.front());
    Q.pop();
  }
  cout<<Max;
  return 0;
}
