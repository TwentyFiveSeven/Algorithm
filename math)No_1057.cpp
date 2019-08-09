#include<iostream>
using namespace std;

int main(){
  int n,x,y,count =0;
  scanf("%d %d %d",&n,&x,&y);

  while(1){
    count++;
    x++;y++;
    if(x/2 == y/2){
      printf("%d",count);
      break;
    }
    x /=2,y/=2;
  }
  return 0;
}
