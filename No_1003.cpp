#include<iostream>

using namespace std;
int zero[41];
int one[41];
int main(){
  int input,i=0,j=0,k=0;
  scanf("%d", &input);
  zero[0] = 1;
  one[0] = 0;
  zero[1] = 0;
  one[1] = 1;
  while(input--){
    scanf("%d",&i);

    if(j>i||i<=1){
      printf("%d %d\n",zero[i],one[i]);
    }else{
      for(k =2;k<=i;k++){
        zero[k] = zero[k-1] +zero[k-2];
        one[k] = one[k-1] + one[k-2];
      }
      printf("%d %d\n",zero[i],one[i]);
    }
    j=i;
  }
}
