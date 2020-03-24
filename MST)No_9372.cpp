#include<iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T,a,b,x,y;
  cin>>T;
  while(T--){
    cin>>a>>b;
    for(int i=0;i<b;i++)
      cin>>x>>y;
    cout<<a-1<<'\n';
  }
  return 0;
}
