#include<iostream>
using namespace std;

int main(){
  int a;
  scanf("%d",&a);
  int temp = a*2-1,k=0;
  for(int i=0;i<temp;i++){
    for(int j=0;j<k+1;j++){
      printf("*");
    }
    if(i<a-1){
      k++;
    }else
      k--;
    printf("\n");
  }
}
