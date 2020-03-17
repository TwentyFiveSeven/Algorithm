#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
int arr[1001], dp[1001],N;
vector<int> V;

void print(int i){
  if( i == 0) return;
  print(V[i]);
  printf("%d ",arr[i]);
}

int main(){
  scanf("%d",&N);
  for(int i=1;i<=N;i++){
    scanf("%d",&arr[i]);
    dp[i] = 1;
  }
  V.push_back(0);V.push_back(0);
  for(int i=2;i<=N;i++){
    V.push_back(0);
    for(int j=1;j<=i-1;j++){
      if(arr[i]>arr[j] && dp[j] +1 > dp[i]){
        dp[i] = dp[j] +1;
        V[i] = j;
      }
    }
  }
  int Max = 0,save = 0;
  for(int i=1;i<=N;i++) Max < dp[i] ? Max = dp[i],save = i : Max = Max;
  printf("%d\n",Max);
  print(save);
  return 0;
}
