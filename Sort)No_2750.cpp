#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> V;
int main(){
  int n,a;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a);
    V.push_back(a);
  }
  sort(V.begin(),V.end());
  for(int i=0;i<n;i++){
    printf("%d\n",V[i]);
  }
  return 0;
}
