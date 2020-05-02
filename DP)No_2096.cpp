#include<iostream>
#include<algorithm>
using namespace std;
pair<int,int> V[3];
int main(){
  int N,a,b,c,d,e,f;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>a>>b>>c;
    d = V[0].first;
    e = V[1].first;
    f = V[2].first;
    V[0].first = min(d,e) +a;
    V[1].first = min({d,e,f})+b;
    V[2].first = min(e,f)+c;
    d = V[0].second;
    e = V[1].second;
    f = V[2].second;
    V[0].second = max(d,e)+a;
    V[1].second = max({d,e,f})+b;
    V[2].second = max(e,f)+c;
  }
  cout<<max({V[0].second,V[1].second,V[2].second})<<' '<<min({V[0].first,V[1].first,V[2].first});
  return 0;
}
