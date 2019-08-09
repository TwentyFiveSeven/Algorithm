#include<iostream>
#include<math.h>
using namespace std;

int n,prohibition[10],save = 1000000,ans=0;

int check(int value){
  int cnt =0;
  while(value){
    if(prohibition[value%10]) return -1;
    value /= 10;
    cnt++;
  }
  return cnt;
}

int main(){ // 목표점으로부터 큰 수 중 가장 작은 것과 작은 수 중 가장 큰것, 0부터 왔을 때의 최솟값을 비교한다.
  int i,num,m,tmp,count=0,Tcount=0;
  scanf("%d",&n);
  scanf("%d",&m);

  for(i=1;i<=m;i++){
    scanf("%d",&num);
    prohibition[num] = 1;
  }
  save = abs(n-100);
  if(!prohibition[0]) save = save <n+1 ? save : n+1;  // 구하는 값이 50보다 작을 때 0부터 시작하는 값이 빠르다.
  for(i=n;i<=999901;i++){  //큰 수 중에 가장 작은 것.
    ans = check(i);
    if(ans>0){
       save = min(save,ans+abs(n-i));
       break;
    }
  }
  for(i=n;i>=0;i--){  //작은 수 중에 가장 큰 것.
    ans = check(i);
    if(ans>0){
      save = min(save,ans+abs(n-i));
      break;
    }
  }


  printf("%d",save);

  return 0;
}
