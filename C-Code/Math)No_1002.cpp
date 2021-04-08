#include<iostream>
using namespace std;

int main(){
  int x1,y1,r1,x2,y2,r2,t;
  scanf("%d",&t);
  while(t--){
    scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
    if(r1 > r2){
      int tmp1 = x1; x1 = x2; x2 = tmp1;
      int tmp2 = y1; y1 = y2; y2 = ymp2;
      int tmp3 = r1; r1 = r2; r2 = tmp3;
    }
    int dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    int value = (r1+r2)*(r1+r2);
    if(x1 == x2 && y1 == y2){
      if(r1 == r2)
        printf("-1\n");
      else
        printf("0\n");
    }else{
      if(x1 > x2)
    }
  }
}
