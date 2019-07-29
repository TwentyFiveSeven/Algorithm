#include<string>
#include<iostream>

using namespace std;

int main(){
  string a,b;
  int cnt = 0,ans =0,i,j;
  cin>>a>>b;
  for(i=0;i<=b.size()-a.size();i++){
    cnt = 0;
    for(j=0;j<a.size();j++){
      if(b[i+j]==a[j]) cnt++;
    }
    ans = max(cnt,ans);
  }
  // printf("%d %d",a.size(),a.size()-ans);
  printf("%d",a.size()-ans);

  return 0;
}
