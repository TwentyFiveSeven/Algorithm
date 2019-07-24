#include<iostream>
#include<math.h>
#include<algorithm>
#include<set>
using namespace std;

set<int> s1;  //계속 같은 숫자가 반복 저장되므로 set으로 해결.
set<int>::iterator iter;  //iterator
int sinkerN,marbleN,sinker[31],marble;


void DP(){  //DP를 통해서 추를 왼쪽 오른쪽 이동하므로써 갖을 수 있는 모든 값을 set에 저장한다.
  int i,j,tmp=0,left=0,right=0;
  s1.insert(sinker[1]);  //첫 값은 바로 입력해준다.
  for(i=2;i<=sinkerN;i++){  //두번 째 값부터 연산시작.
    set<int> s2(s1);  //s1 set과 같은 s2 set을 만든다. => 연산과정에서 s1에 값이 추가되므로 반복문에 이상발생.
    tmp = s1.size();  //s1의 size를 저장 마찬가지 문제지만 s2를 만드므로 해결.
    for(iter = s2.begin(),j=0;j<tmp;iter++,j++){  //iterator를 처음부터 진행
      left = abs(*iter-sinker[i]);  //뺏을 떄의 값
      right = abs(*iter+sinker[i]); //더했을 때의 값
      s1.insert(sinker[i]); // 추 자체의 값
      s1.insert(left);
      s1.insert(right);
    }
  }
}

int main(){
  int i,j,flag=0,value=0;
  scanf("%d",&sinkerN);
  for(i=1;i<=sinkerN;i++){
    scanf("%d",&sinker[i]);
  }
  DP();

  scanf("%d",&marbleN);
  for(i=1;i<=marbleN;i++){
    scanf("%d",&marble);
    value = *s1.find(marble);
    if(value==marble) printf("Y "); //set에 값이 있는지 확인. 있다면 marble과 값은값
    else printf("N ");  //없다면 가장 끝에있는 end값 return
  }
  return 0;
}
