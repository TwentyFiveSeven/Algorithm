#include<iostream>
#include<vector>
using namespace std;
vector<int> V;
int main(){
  int n,sum =0,a=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a);
    if(a == 0) V.pop_back();
    else V.push_back(a);
  }
  for(int i=0;i<V.size();i++){
    sum += V[i];
  }
  printf("%d",sum);
  return 0;
}
