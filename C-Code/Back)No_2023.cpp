#include<iostream>
#include<queue>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int start[5]= {0,2,3,5,7};
int ing[5] = {0,1,3,7,9};
int n;
int divid=1;
queue<int> Q;
vector<int> V;

int promising(int val){
  int i;
  for(i=2;i<=sqrt(val);i++){  //소수 확인 법은 2부터 제곱근까지만 확인하면 된다.
    if(val%i ==0) return 0;
  }
  return 1;
}


int back(){
  int i,j,tmp,val;
  while(!Q.empty()){  //Q를 이용해 Q가 빌 때 까지 진행.
    tmp = Q.front();  //Q에 저장된 값을 가져온다.
    Q.pop();
    if(tmp/divid){  //만일 n의 배수만큼 즉 n=3 => divid = 1000 의 값이 1보다 크다면 V에 저장한다.
      V.push_back(tmp);
      continue;
    }
    for(i=1;i<=4;i++){
      val=tmp*10+ing[i];  //중간에 들어갈 수 있는 숫자 1,3,7,9 만 확인. 기존값 x10 + (1,3,7,9)를 확인한다.
      if(promising(val)){ //유망한지 확인.
        Q.push(val);
      }
    }
  }
}

int main(){
  int i,j,k;

  scanf("%d",&n);
  for(i=1;i<=n-1;i++) divid*=10;
  for(i=1;i<=4;i++){
    Q.push(start[i]);
  }
  back();
  sort(V.begin(),V.end(),greater<int>());
  k = V.size();
  for(i=0;i<k;i++){
    printf("%d\n",V.back());
    V.pop_back();
  }

  return 0;
}
