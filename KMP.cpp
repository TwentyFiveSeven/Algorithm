#include <iostream>
#include <cstdio>
#incldue <string>

using namespace std;

void fail(char P[],int F[]){
  int i=1, j=0, m=strlen( P );
  // 자기 자신 밖에 없기 때문에 -1
  F[0] = -1;
  // 따라서 i는 1부터, 패턴의 최대 길이 -1 까지다.
  while( i<m ) {
    if(P[j] == P[i]) { // j와 i의 인덱스의 데이터가 같으면
      F[i++] = j++;        // j 인덱스를 실패값으로 기록(가장 마지막 인덱스 값)
    } else if( j>0 ) {  // j가 0보다 크다는 것은 패턴의 앞 일부분이 일치한다는 것.
      j = F[j-1]+1;                  // j에는 실패함수의 인덱스 j에 있는 데이터에 +1을 하여 넣는다.
                        // 서로 다른 부분을 만났으므로 같은 부분에서 한칸 뒤를 가르켜준다.
    } else {             // 같은 접미어가 발견되지 않으면 -1
        F[i++] = -1;
    }
  }
}


int main(){
  int t;
  string st;

  scanf("%d",&t);
  char **p = new char*[t];

  for(int i=0; i<t;i++){
    scanf("%s",&st);
    p[i] = new char[st.length()];
    int *f = new int[st.length()];
    for(int j=0; j<st.length();j++){
      p[i][j]=st.at(i);
    }
  }

  scanf("%s",&st);
  char *s = new char[st.length()];
  for(int i=0; i<st.length();i++){
    s[i]=st.at(i);
  }
}
