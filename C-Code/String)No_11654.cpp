#include<iostream>

using namespace std;

int main(){
  int n,sum = 0;
  char a;
  scanf("%d",&n);
  scanf("%c",&a);
  for(int i=0;i<n;i++){
    scanf("%c",&a);
    sum += a -48;
  }
  printf("%d",sum);
  return 0;
}
