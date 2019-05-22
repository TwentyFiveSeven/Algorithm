#include<iostream>
#include<algorithm>
using namespace std;

int t[16];
int p[16];
int maxp=0,n;
void bf(int sum,int i){
  int j;

  if(i+t[i]-1>n){
    if(sum>maxp)
      maxp=sum;
    return;
  }

  sum += p[i];
  i +=t[i];

  for(j=i;j<=n;j++){
    bf(sum,j);
  }

  if(sum>maxp)
    maxp=sum;
}

int main(){
  int i,j,sum=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d %d",&t[i],&p[i]);
  }

  for(i=1;i<=n;i++){
    bf(0,i);
  }
  printf("%d",maxp);

  return 0;
}
