#include<iostream>
#include<string.h>
using namespace std;

char arr[2201][2201];

void find(int x,int y,int n){
  if(n == 1){
    arr[x][y] = '*';
    return;
  }

  int div = n/3;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(i==1&&j==1)
        ;
      else
        find(x+(i*div),y+(j*div),div);
    }
  }
}

int main(){
  int n;
  scanf("%d",&n);
  memset(arr,' ',sizeof(arr));
  find(0,0,n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      printf("%c",arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}
