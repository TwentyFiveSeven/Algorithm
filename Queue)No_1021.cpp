#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> V;

void two(){
  V.push_back(V.front());
  V.erase(V.begin());
}

void three(){
  V.insert(V.begin(),V.back());
  V.pop_back();
}
int main(){
  int n,m,tmp,ans=0;
  scanf("%d %d",&n,&m);
  for(int i=1;i<=n;i++){
    V.push_back(i);
  }
  for(int i=0;i<m;i++){
    scanf("%d",&tmp);
    auto temp = find(V.begin(),V.end(),tmp);
    int location = temp - V.begin();
    if(location == 0){
      V.erase(V.begin());
    }else{
      if(location+1 > V.size()-(location)){
        location = V.size()-(location);
        while(location--){
          three();
          ans++;
        }
      }else{
        while(location--){
          two();
          ans++;
        }
      }
      V.erase(V.begin());
    }
  }
  printf("%d",ans);
  return 0;
}
