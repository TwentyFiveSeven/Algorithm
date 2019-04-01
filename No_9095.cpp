#include<iostream>
using namespace std;

int dp[11]={1,2,4,0,0,0,0,0,0,0,0};

int mul(int i){
    return dp[i-3]+dp[i-2]+dp[i-1];
}


int main(){
  int n,d,i;
  scanf("%d",&n);

  for(i=3; i<11;i++){
    dp[i] = mul(i);
  }

  for(i =0;i<n;i++){
    scanf("%d",&d);
    printf("%d\n",dp[d-1]);
  }
  return 0;
}
