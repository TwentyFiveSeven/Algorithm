#include<iostream>
using namespace std;

int main(){
  int max =0,num,save=0;
  for(int i=1;i<=9;i++){
    scanf("%d",&num);
    if(num>max){
      max = num;
      save = i;
    }
  }
  printf("%d\n%d",max,save);
  return 0;
}
