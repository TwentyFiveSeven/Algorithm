#include<iostream>
#include<math.h>
using namespace std;

int so(int k){
  for(int i=2;i<=sqrt(k);i++){
    if(k%i ==0) return 0;
  }
  return 1;
}

int main(){
  int start,end;
  scanf("%d %d",&start,&end);
  for(int i=start; i<=end;i++){
    if(i == 1) continue;
    if(so(i)) printf("%d\n",i);
  }
  return 0;
}
