#include<iostream>
using namespace std;

int dp[301][301];
int main(){
  int i,j,fcont=0,scont=0,n=0,m=0,k=0,x=0,y=0,a=0,b=0,tmp=0;
  scanf("%d %d",&n,&m);

  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
      scanf("%d",&tmp);
      dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+tmp;
    }
  }
  scanf("%d",&k);
  for(i=1;i<=k;i++){
    scanf("%d %d %d %d",&x,&y,&a,&b);
    printf("%d\n",dp[a][b]+dp[x-1][y-1]-dp[a][y-1]-dp[x-1][b]);
  }
}
