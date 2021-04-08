#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int>> V;
vector<int> A;
int ans[100];
bool compare(pair<int,int> fir,pair<int,int> sec){
    return fir.first < sec.first;
}

int main(){
  int n,a,b,i,maxN=0,count=0,j,max=0,k;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d",&a,&b);
    V.push_back(make_pair(a,b));
  }
  sort(V.begin(),V.end(), compare);
  for(i=0;i<V.size();i++){
    A.push_back(V[i].second);
  }
  for(i=0;i<n;i++){
    max = 0;
    for(j=0;j<=i;j++){
      if(A[j]<A[i]&&ans[j]>max){
        ans[i] = ans[j]+1;
        max = ans[j];
        if(ans[i]>maxN) maxN = ans[i];
      }
    }
    if(ans[i] ==0){
      ans[i] = 1;
    }
  }
  printf("%d",A.size()-maxN);
  return 0;
}
