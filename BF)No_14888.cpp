#include<iostream>

using namespace std;

int arith[10],arr[11],N,check[10],countN; //BF를 통해서 모든 경우의 수를 확인후에 만들 수 있는 최댓값, 최솟값을 찾는다.
int Max = -1000000001,Min= 1000000001;
void bf(int sum,int depth){
  int i;
  if(depth == N){
    if(sum>Max)Max = sum;
    if(sum<Min)Min = sum;
    return;
  }
  for(i=0;i<N-1;i++){
    if(check[i]==1) continue;
    check[i] = 1;
    switch(arith[i]){
      case 0 :
        bf(sum+arr[depth],depth+1);
        break;
      case 1 :
        bf(sum-arr[depth],depth+1);
        break;
      case 2 :
        bf(sum*arr[depth],depth+1);
        break;
      case 3 :
        bf(sum/arr[depth],depth+1);
        break;
    }
    check[i] = 0;
  }
}

int main(){
  int i,j;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&arr[i]);
  }
  for(i=0;i<4;i++){
    scanf("%d",&j);
    while(j-- !=0)
      arith[countN++] = i;
  }
  bf(arr[0],1); //첫번째 수와, 1을 넣어준다.
  printf("%d\n%d",Max,Min);
  return 0;
}
