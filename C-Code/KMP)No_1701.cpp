#include<iostream>
#include<string>
#include<vector>
using namespace std;

int fail(string s){
  int i,sizeN = s.size(),j,maxN=0;
  j=0;
  vector<int> pi(sizeN,0);
  for(i=1;i<sizeN;i++){
    while(j>0&&s[i] != s[j])
      j = pi[j-1];
    if(s[i] == s[j]){
      pi[i] = ++j;
      if(j>maxN)maxN = j;
    }
  }
  return maxN;
}

int main(){
  int i,j,sizeN,maxN=0;
  string s;
  cin>>s;
  sizeN = s.size();
  if(sizeN == 1) {
    printf("0");
    return 0;
  }
  for(i=0;i<sizeN;i++){
    string sub = s.substr(i,sizeN); // 앞에서부터 하나씩 제외시키면서
    int ans = fail(sub);  //모든 글자의 경우를 확인할 수 있다. =>앞부터 끝까지 모두를 포함하면 맨 앞에서 시작하는 문자를 모두
    if(ans>maxN) maxN = ans;  //확인 가능하기 때문이다.
  }
  printf("%d",maxN);
  return 0;
}
