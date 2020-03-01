#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans,num,save;
vector<char> C;
int main(){
  int n,count =0,a;
  scanf("%d",&n);
  for(int i =1;i<=n;i++){
    scanf("%d",&a);
    ans.push_back(a);
    num.push_back(n+1-i);
  }
  reverse(ans.begin(),ans.end());
  while(!ans.empty()){
    int val = ans.back();
    while(1){
      if(num.back() > val||num.empty()) break;
      save.push_back(num.back());
      num.pop_back();
      C.push_back('+');
    }
    if(val == save.back()){
      C.push_back('-');
      save.pop_back();
      ans.pop_back();
    }else{
      printf("NO");
      return 0;
    }
  }
  int size = C.size();
  for(int i=0;i<size;i++){
    printf("%c\n",C[i]);
  }
}
