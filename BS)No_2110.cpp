#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> V;
int n,c,ans;
void bs(long long start, long long end){
  if(start > end) return;
  long long mid = (end+start)/2;
  int val = V[0];
  int count =0;
  for(int i=1;i<n;i++){
    if(V[i]-val >= mid){
      val = V[i];
      count++;
    }
  }
  if(count<c-1){
    bs(start,mid-1);
  }else{
    ans < mid ? ans = mid : mid = mid;
    bs(mid+1,end);
  }
}

int main(){
  int a;
  scanf("%d %d",&n,&c);
  for(int i=0;i<n;i++){
    scanf("%d",&a);
    V.push_back(a);
  }
  sort(V.begin(),V.end());
  if(c == 2) {
    printf("%d",V.back()-V.front());
    return 0;
  }
  bs(0,V[n-1]-V[0]);
  printf("%d",ans);
  return 0;
}
