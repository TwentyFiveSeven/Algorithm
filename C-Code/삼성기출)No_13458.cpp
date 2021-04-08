#include<iostream>
using namespace std;

int n,A[1000002],B,C;
long long ans;

int main(){
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  scanf("%d %d",&B,&C);

  for(i=0;i<n;i++){
    A[i] = A[i]-B;
    if(A[i]>0){
      if((A[i]%C)!=0){
        ans += A[i]/C +1;
      }else
        ans += A[i]/C;
    }
    ans++;
  }
  printf("%lld",ans); //long long  입력, 출력 lld 집중하자
  return 0;
}
