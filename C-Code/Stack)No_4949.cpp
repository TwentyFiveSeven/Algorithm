#include<iostream>
#include<vector>
using namespace std;
vector<char> a;
int main(){
  string s="";
  while(s != "."){
    getline(cin,s);
    if(s == ".") break;
    int size = s.size();
    for(int i=0;i<size;i++){
      if(s[i] == '('){
        a.push_back('(');
      }else if(s[i] == ')'){
        if(a.back() != '('){
          a.push_back(')');
          break;
        }
        a.pop_back();
      }else if(s[i] == '['){
        a.push_back('[');
      }else if(s[i] == ']'){
        if(a.back() != '['){
          a.push_back(']');
          break;
        }
        a.pop_back();
      }
    }
    if(!(a.size())) printf("yes\n");
    else printf("no\n");
    while(!a.empty()) a.pop_back();
  }
  return 0;
}
