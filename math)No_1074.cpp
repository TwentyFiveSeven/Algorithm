#include<iostream>
#include<math.h>
using namespace std;

int xi[4] = {0,0,1,1};
int yi[4] = {0,1,0,1};

int count,X,Y;

void DC(int n,int x,int y){
  int i,j,nx,ny;
  if(n==2){
    for(i=0;i<4;i++){
      count++;
      nx = x + xi[i];
      ny = y + yi[i];
      if(nx == X &&ny == Y){
        printf("%d",count-1);
        return;
      }
    }
    return;
  }
  DC(n/2,x,y);
  DC(n/2,x,y+n/2);
  DC(n/2,x+n/2,y);
  DC(n/2,x+n/2,y+n/2);
}

int main(){
  int n,i=1,j=1,nx,ny,count = 0;
  scanf("%d %d %d",&n,&X,&Y);
  DC(pow(2,n),0,0);
  return 0;
}
