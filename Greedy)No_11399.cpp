#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> V;
int main(){
  int n,a,sum=0,value=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a);
    V.push_back(a);
  }
  sort(V.begin(),V.end());
  for(int i=0;i<n;i++){
    sum = V[i]+sum;
    value += sum;
  }
  printf("%d",value);
  return 0;
}
