#include<iostream>
#include<math.h>
using namespace std;

int N,arr[20][20],check[20],team[20],Min = 1000000001;
int sum1,sum2;

void bf(int st,int depth){
  int i,j;
  if(depth == N/2){ //만약 절반의 팀이 이루어졌다면
    sum1 =0,sum2 =0;
    for(i=0;i<N;i++){
      for(j=0;j<N;j++){
        if(team[i] == 1 && team[j] == 1){ // 팀 1끼리의 연산
          sum1+= arr[i][j];
          continue;
        }
        else if(team[i] ==2&& team[j] == 2){  // 팀 2끼리의 연산
          sum2 += arr[i][j];
        }
      }
    }
    if(abs(sum1-sum2)<Min) Min = abs(sum1-sum2);  //차이값중 최솟값을 구한다.
  }
  for(i=st;i<N;i++){  // 겹치지 않기 위해서 현재 자릿수가 증가할 수록 앞에 수보다 큰 수만 오도록 한다.
    if(depth==0&&i!=0) return;  // 가장 앞자리가 1에서 바뀌는 순간부터는 계속 겹치는 조합이기 때문에 바로 return;
    if(check[i]) continue;
    check[i] = 1;
    team[i] = 2;
    bf(i+1,depth+1);  //재귀호출
    team[i] = 1;  //원상복귀
    check[i] = 0; //원상복귀
  }
}

int main(){
  int i,j,sum;
  fill_n(team,20,1);
  scanf("%d",&N);
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      scanf("%d",&arr[i][j]);
      sum += arr[i][j];
    }
  }
  Min = sum;
  bf(0,0);
  printf("%d",Min);
  return 0;
}
