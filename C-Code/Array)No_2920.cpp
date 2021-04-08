#include<iostream>
using namespace std;
int arr[8],save = 0,flag =0,Acount=0,Dcount=0;
int main(){
  for(int i=0; i<8;i++){
    scanf("%d",&arr[i]);
  }
  for(int i=0;i<8;i++){
    if(arr[i] == i+1)
      Acount++;
  }
  if(Acount == 8){
    printf("ascending");
    return 0;
  }
  for(int i=0;i<8;i++){
    if(arr[i] == 8-i)
      Dcount++;
  }
  if(Dcount == 8){
    printf("descending");
    return 0;
  }
  printf("mixed");

  return 0;
}
