#include<iostream>
#include<vector>
using namespace std;

vector<int> V,ans;
int main(){
  int n,k,num;
  scanf("%d %d",&n,&k);
  for(int i=1;i<=n;i++){
    V.push_back(i);
  }
  num = k-1;
  while(!V.empty()){
    ans.push_back(V[num]);
    V.erase(V.begin()+num);
    if(V.empty()) break;
    num = (num-1+k)%V.size();
  }
  printf("<");
  for(int i=0;i<ans.size();i++){
    if(i == ans.size()-1) {
      printf("%d>",ans[i]);
      break;
    }
    printf("%d, ",ans[i]);
  }
  return 0;
}
