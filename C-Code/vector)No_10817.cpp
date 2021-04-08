#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> V;

int main(){
  int a,b,t,tmp,r;
  scanf("%d %d",&t,&r);
  for(int i=0;i<t;i++){
    scanf("%d",&tmp);
    if(tmp<r)
      V.push_back(tmp);
  }
  return 0;
}
