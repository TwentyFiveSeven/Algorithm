#include<iostream>
using namespace std;

int ax,ay,az,cx,cy,cz;

int main(){
  scanf("%d %d %d",&ax,&ay,&az);
  scanf("%d %d %d",&cx,&cy,&cz);

  printf("%d %d %d",cx-ax,cy/ay,cz-ax);
  return 0;
}
