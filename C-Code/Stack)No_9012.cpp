#include<iostream>
#include<vector>
using namespace std;
vector<char> V;
int main(){
  int t;
  char c;
  string s;
  scanf("%d",&t);
  scanf("%c",&c);
  while(t--){
    getline(cin,s);
    int size = s.size();
    for(int i=0;i<size;i++){
      if(s[i]=='('){
        V.push_back('(');
      }else{
        if(V.size()==0){
          V.push_back(')');
          break;
        }
        V.pop_back();
      }
    }
    if(V.empty()){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
    while(!V.empty()) V.pop_back();
  }
  return 0;
}
