#include<iostream>
using namespace std;

int find(int n, int a){
  int i;
  if(n<a){
    i = a;
    a = n;
    n = i;
  }

  while(a>0){
    i = n % a;
    n = a;
    a = i;
  }
  return n;
}

int main(){
  int n,first,a;
  scanf("%d",&n);
  scanf("%d",&first);
  for(int i=1;i<n;i++){
    scanf("%d",&a);
    if(first%a == 0){
      a = first/a;
      printf("%d/1\n",a);
    }else if(a%first == 0){
      a = a/first;
      printf("1/%d\n",a);
    }else{
      int val = find(first,a);
      printf("%d/%d\n",first/val,a/val);
    }
  }
  return 0;
}
