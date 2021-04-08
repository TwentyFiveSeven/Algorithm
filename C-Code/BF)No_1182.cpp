#include<iostream>

using namespace std;

int arr[21];
int n,s,countN;


void rec(int i,int num){
  int k,m;
  if(num == s){
    countN++;
  }
  for(k=i+1;k<=n;k++){
    rec(k,num+arr[k]);  //반복문과 재귀함수를 통해서 모든 조합을 계산해본다.
  }
}

int main(){
  int i,j;

  scanf("%d %d",&n,&s);
  for(i=1;i<=n;i++){
    scanf("%d",&arr[i]);
  }

  for(i=1;i<=n;i++){
    rec(i,arr[i]);  //앞에 숫자부터 하나씩 뒤에 수들과의 조합을 본다.
  }

  printf("%d",countN);
  return 0;
}
