#include<iostream>
#include<map>
using namespace std;

map<string,int> m;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N,M,count=0;
  string s;
  cin>>N>>M;
  for(int i=0;i<N;i++){
    cin>>s;
    m.insert({s,0});
  }
  for(int i=0;i<M;i++){
    cin>>s;
    if(m.count(s))
      count++;
  }
  cout<<count;
  return 0;
}
