#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> fail(string p){
  int i=1,j=0;
  int m = p.size();
  vector<int> f(m,0);

  while(i<m){
    if(p[i]==p[j]){
      f[i++]=(j++);
    }else if(j>0){
      j=f[j-1];
    }else{
      f[i++]=0;
    }
  }
  return f;
}

int kmp(string p){
  int i,j,ans;
  int m = p.size();
  vector<int> f(m,0);

  for(i=0;i<m;i++){
    if(f[i]>0){
      if(f[i]==1){
        if(i==m-1){
          ans = i;
          break;
        }else if(f[i]-f[i+1]!=-1){
          
        }
      }
    }
  }
  return ans;
}

int main(){
  int size,i,ans;
  string p;

  getline(cin, p);
  ans = kmp(p);
  printf("%d",ans);

}
