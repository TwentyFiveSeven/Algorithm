#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> V;
int main(){
  int n=0,value=0,i,max =0,ans=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&value);
    V.push_back(value);
  }
  sort(V.begin(),V.end());  //무게를 순서대로 정렬
  for(i=0;i<n;i++){ //후에 무게의 순서 = i 일 때 ans = 무게 x (n-i) 의 값중 최대 값을 구한다.
    ans = V[i]*(n-i);
    if(ans>max) max = ans;
  }
  printf("%d",max);
  return 0;
}
