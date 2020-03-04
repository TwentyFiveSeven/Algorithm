#include<iostream>
using namespace std;

int main(){
  int a,b;
  while(1){
    scanf("%d %d",&a,&b);
    if(!a && !b) break;
    if(b%a == 0) printf("factor\n");
    else if(a%b == 0) printf("multiple\n");
    else{
      printf("neither\n");
    }
  }
  return 0;
}
