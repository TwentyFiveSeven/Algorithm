#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> V;

bool cmp(pair<int,int> a, pair<int,int> b){
  if(a.second != b.second){
    return a.second < b.second;
  }else
    return a.first < b.first;
}
int main(){
  int n,a,b;
  scanf("%d",&n);
  for(int i=0; i<n;i++){
    scanf("%d %d",&a,&b);
    V.push_back(make_pair(a,b));
  }
  sort(V.begin(),V.end(),cmp);
  for(int i=0;i<n;i++){
    printf("%d %d\n",V[i].first,V[i].second);
  }
  return 0;
}
