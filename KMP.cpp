#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> fail(string p){
  int i=1, j=0, m=p.size();
  vector<int> f(m,0);
  // 자기 자신 밖에 없기 때문에 -1
  f[0] = 0;
  // 따라서 i는 1부터, 패턴의 최대 길이 -1 까지다.
  while( i<m ) {
    if(p[j] == p[i]) { // j와 i의 인덱스의 데이터가 같으면
      f[i++] = (j++);        // j 인덱스를 실패값으로 기록(가장 마지막 인덱스 값)
    } else if( j>0 ) {  // j가 0보다 크다는 것은 패턴의 앞 일부분이 일치한다는 것.
      j = f[j-1];                  // j에는 실패함수의 인덱스 j에 있는 데이터에 +1을 하여 넣는다.
                        // 서로 다른 부분을 만났으므로 같은 부분에서 한칸 뒤를 가르켜준다.
    } else {             // 같은 접미어가 발견되지 않으면 -1
        f[i++] = 0;
    }
  }
  return f;
}

int kmp(string s, string p){
  int i=0,j=0,count=0;
  int m = s.size();
  int n = p.length();
  vector<int> f = fail(p);
  while(i<s.size()){
    if(s[i]==p[j]){
      if(j==n-1){
        count++;
        j=f[j-1],i++;
      }else{
        i++;j++;}
    }else if(j-1<0){
      i++;j=0;
    }else{
      j = f[j-1];
    }
  }
  return count;
}


int main(){
  int i,j;
  string s, p;

  getline(cin, s);
  getline(cin, p);
  auto ans = kmp(s,p);
  printf("\n%d",(int)ans);
}
