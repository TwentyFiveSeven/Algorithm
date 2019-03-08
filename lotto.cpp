#include<iostream>
#include<vector>
using namespace std;

int n;
int ans[6];
vector<int> arr;

void dfs(int depth, int num){
  int i;
  if(depth ==6){
    for(int i=0;i<6;i++){
      cout<<ans[i]<<" ";
    }
    cout <<'\n';
    return;
  }
  for(int i = num; i <n; i++){
    ans[depth] = arr[i];
    dfs(depth+1,i+1);
    ans[depth] = -1;
  }
}

int main(){
  int i,j,num;
  while(1){
    cin>>n;
    arr.clear();

    if(n==0)break;

    for(int i=0;i<n;i++){
      cin >>num;
      arr.push_back(num);
    }

    dfs(0,0);
    cout<<'\n';
  }
  return 0;
}
