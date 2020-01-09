#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[101];
vector<int> V;
int n,value;
void bf(int st,int val, int depth){
  // printf("st : %d, val : %d, depth : %d\n",st,val,depth);
  if(val>value)
    return;
  else if(depth>3){
    V.push_back(val);
    return;
  }

  for(int i=st;i<=n;i++){
    val += arr[i];
    bf(i+1,val,depth+1);
    val -= arr[i];
  }
}

int main(){
  scanf("%d %d",&n,&value);
  for(int i=1;i<=n;i++){
    scanf("%d",&arr[i]);
  }
  bf(1,0,1);
  sort(V.begin(),V.end());
  printf("%d",V.back());
  return 0;
}
