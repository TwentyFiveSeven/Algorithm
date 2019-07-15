#include<iostream>
#include<algorithm>
using namespace std;

int n,countN;

int promising(int queen[],int num){
  int i;
  for(i=1;i<num;i++){
    if(queen[i] == queen[num]) {return 0;}  // 같은 행에 있는지 확인.
    if(queen[i]-queen[num] == i-num) {return 0;}  //위 대각선에 있는지 확인.
    if(queen[num]-queen[i] == i-num) {return 0;}  //아래 대각선에 있는지 확인.
    }
    return 1;
}

void queens(int queen[],int num){   //배열 및 현재 탐색 위치를 넘긴다.
  int i,j;
  if(num ==n+1){
    countN++;
  }else{
    for(i=1;i<=n;i++){
      queen[num] = i;   // 현재 탐색 열의 행위치 변경
      if(promising(queen,num)){ //promising을 이용해서 유망 확인.
        queens(queen,num+1);
      }
    }
  }
}

int main(){
  int i,j;
  int queen[16];
  fill_n(queen,16,0);

  scanf("%d",&n);

  queens(queen,1);
  printf("%d",countN);

  return 0;
}
