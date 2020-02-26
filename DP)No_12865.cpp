#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> V;
int arr[100001];
int main(){
  int n,k,a,b;
  scanf("%d %d",&n,&k);
  for(int i=0;i<n;i++){
    scanf("%d %d",&a,&b);
    V.push_back(make_pair(a,b));
  }

  for(int i=1;i<=n;i++){
    for(int j=k;j>0;j--){
      if(j>=V[i-1].first)
        arr[j] = max(V[i-1].second+arr[j-V[i-1].first],arr[j]);
      else
        arr[j] = arr[j];
    }
  }
  printf("%d",arr[k]);
  return 0;
}
