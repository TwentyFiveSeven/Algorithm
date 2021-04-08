#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> V;
int main(){
  int n,a,b,count=0;
  scanf("%d",&n);
  for(int i =0;i<n;i++){
    scanf("%d %d",&a,&b);
    V.push_back(make_pair(b,a));
  }
  sort(V.begin(),V.end());
  int start = 0,end = V[0].first;
  for(int i=1;i<n;i++){
    if(V[i].second >= end){
      end = V[i].first;
      count++;
    }
  }
  printf("%d",count+1);
  return 0;
}
