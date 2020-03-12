#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

struct cmp{
  bool operator()(int a,int b){
    if(abs(a) == abs(b)){
      return a>b;
    }else
      return abs(a) > abs(b);
  }
};

priority_queue<int,vector<int>,cmp> pq;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N,a;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>a;
    if(!a){
      if(pq.empty()){
        cout<<"0\n";
      }else{
      cout<<pq.top()<<endl;
      pq.pop();
      }
    }else{
      pq.push(a);
    }
  }
  return 0;
}
