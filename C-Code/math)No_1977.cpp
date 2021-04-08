#include<iostream>
#include<math.h>
using namespace std;

int main(){
  int N,M,i,j,n,m,sum=0,save=100001;

  scanf("%d",&M);
  scanf("%d",&N);
  m = sqrt(M);
  n = sqrt(N);
  if(m*m<M) m++;
  for(i=m;i<=n;i++){
    sum += i*i;
    if(save>i*i){
      save = i*i;
    }
  }
  if(sum ==0){
    printf("-1");
    return 0;
  }
  printf("%d\n%d",sum,save);
  return 0;
}
