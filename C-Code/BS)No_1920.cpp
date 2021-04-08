#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> V,check;
int main(){
  int n,m,a,flag = 0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&a);
    V.push_back(a);
  }
  scanf("%d",&m);
  for(int i=0;i<m;i++){
    scanf("%d",&a);
    check.push_back(a);
  }
  sort(V.begin(),V.end());
  for(int i=0;i<m;i++){
    if(check[i]> V[n-1]){
      printf("0\n");
      continue;
    }
    long long left = 0, right = n-1;
    while(left<=right){
      flag = 0;
      long long mid = (left+right)/2;
      if(check[i]>V[mid]){
        left = mid+1;
      }else if(check[i]<V[mid]){
        right = mid-1;
      }else{
        printf("1\n");
        flag = 1;
        break;
      }
    }
    if(flag ==0)
      printf("0\n");
  }
  return 0;
}
