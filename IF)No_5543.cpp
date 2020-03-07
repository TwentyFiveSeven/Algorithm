#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> V;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int a,b,c,d,e;
  cin>>a>>b>>c>>d>>e;
  V.push_back(a);
  V.push_back(b);
  V.push_back(c);
  sort(V.begin(),V.end());
  if(d>e){
    cout<<e+V[0]-50;
  }else
    cout<<d+V[0]-50;
  return 0;
}
