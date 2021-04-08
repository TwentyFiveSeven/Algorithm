#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> fail(string p){
  int i=1,j=0;
  int m = p.size();
  vector<int> f(m,0);
  f[0]=0;

  while(i<m){
    if(p[i]==p[j]){
      f[i++]=(j++)+1;
    }else if(j>0){
      j=f[j-1];
    }else{
      f[i++]=0;
    }
  }
  return f;
}

int main(){
  int i,ans,n;
  string p;
  cin>>n;
  cin>>p;
  // getline(cin, p);
  vector<int> pi = fail(p);
  cout<<n-(int)pi[n-1];

  return 0;
}
