#include<iostream>

using namespace std;

long long int dp[31][31];

int main(){
  int i,j,t=0,half=0;
  long long int n=0,m=0,save =1;

  scanf("%d",&t);
  dp[1][0]=1;dp[1][1]=1;

  while(t--){
    scanf("%lld %lld",&n,&m);

    if(save>=m){      // dp이므로 이미 구한 값은 다시 구하지않고 바로 사용한다.
      printf("%lld\n",dp[m][n]);
    }else{
      for(i=save+1;i<=m;i++){
        half = i/2;
        dp[i][0] =1;
        for(j=1;j<=m/2;j++){
          dp[i][j] = dp[i-1][j-1]+dp[i-1][j];  //조합은 대칭의 관계이므로 절반만 구한다
        }
        for(j=m;j>half;j--){
          dp[i][j] = dp[i][m-j];  //뒤에 절반은 앞에 절반 값을 받아준다.
        }
      }
      printf("%lld\n",dp[m][n]);
      save = m;
    }
  }
  return 0;
}
