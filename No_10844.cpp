#include<iostream>

using namespace std;

int arr[101][11];   //본래 사용하는 공간은 [101][10]이지만 9는 8에대한 연산만 할 수 있으므로 10에 대한 값을 0을 주기위해 패딩.

int main(){
  int input =0,i,j,sum=0;

  scanf("%d",&input);

  arr[1][0]=0;
  for(i=1;i<10;i++){
    arr[1][i]=1;
  }
  for(i=2;i<=input;i++){
    arr[i][0] = arr[i-1][1];    //0의 연산값은 input-1번째의 0-1,0+1에 대한 값의 연산이지만 0-1은 이용할 수 없으므로 0+1에 대한 연산만 해준다.
    for(j=1;j<10;j++){
      arr[i][j] = (arr[i-1][j-1]+arr[i-1][j+1])%1000000000; // i계단에서 j의 값은 i-1계단에서 j-1,j+1값을 가져와서 붙인 것과 같기 때문에
    }                                                       // i-1계단의 j-1,j+1 값의 수 만큼을 가져와서 붙여준다.
  }
  for(i=0;i<10;i++){
    sum += arr[input][i];
    sum %= 1000000000;
  }

  printf("%d",sum);

  return 0;
}
