#include<iostream>
#include<string>
#include<vector>
using namespace std;

int Len(int l){
  int ret=0;
  while(l){
    ret++;
    l/=10;
  }
  return ret;
}

int solve(string s,int n){
  int i,j,ret=0,length=1;
  int size = s.size();
  for(i=0;i<size;i+=n){
    if(i+n+n>size || s.substr(i,n) != s.substr(i+n,n)){
      cout<<s.substr(i,n)<<" "<<s.substr(i+n,n)<<endl;
      ret += min(n,size-i);
      if(length >1) ret += Len(length);
      length = 1;
    }else
      length++;
  }
  return ret;
}

int solution(string s){
  int i,j,ret;
  int size = s.size();
  ret = size;
  for(i=1;i<size;i++){
    ret = min(ret,solve(s,i));
  }
  return ret;
}

int main(){
  string s;
  cin>>s;
  printf("%d",solution(s));
  return 0;
}
