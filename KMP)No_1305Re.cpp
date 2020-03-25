#include<iostream>
#include<vector>
using namespace std;

int N;
int Fail(string s){
  int size = s.size(),j=0;
  vector<int> pi(size,0);
  for(int i=1;i<size;i++){
    if(j>0 && s[i] != s[j])
      j = pi[j-1];
    if(s[i] == s[j])
      pi[i] = ++j;
  }
  return pi[size-1];
}

int main(){
  string s;
  cin>>N;
  cin>>s;
  int ans = Fail(s);
  cout<<N-ans;
  return 0;
}
