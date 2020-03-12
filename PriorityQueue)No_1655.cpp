#include<iostream>
#include<queue>
using namespace std;
priority_queue<int> MaxH;
priority_queue<int,vector<int>,greater<int>> MinH;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N,a;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>a;
    if(MinH.size() < MaxH.size()){
      MinH.push(a);
    }else
      MaxH.push(a);
    if(!MinH.empty()&&MinH.top() < MaxH.top()){
      int temp = MinH.top();
      MinH.pop();
      MinH.push(MaxH.top());
      MaxH.pop();
      MaxH.push(temp);
    }
    cout<<MaxH.top()<<'\n';
  }
  return 0;
}
