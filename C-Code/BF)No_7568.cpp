#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>> V;
int arr[50];
int main(){
  int n,a,b;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d %d",&a,&b);
    V.push_back(make_pair(a,b));
  }
  for(int i=0;i<V.size();i++){
    for(int j=0;j<V.size();j++){
      if(j==i) continue;
      if(V[i].first<V[j].first&&V[i].second<V[j].second)
        arr[i]++;
    }
  }
  for(int i=0;i<n;i++){
    printf("%d ",arr[i]+1);
  }
  return 0;
}
