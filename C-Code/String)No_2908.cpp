#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
  string a,b;
  cin>>a>>b;
  char tmp;
  tmp = a[0];
  a[0] = a[2];
  a[2] = tmp;
  tmp = b[0];
  b[0] = b[2];
  b[2] = tmp;
  int c,d;
  c = atoi(a.c_str());
  d = atoi(b.c_str());
  if(c > d)
    printf("%d",c);
  else
    printf("%d",d);

  return 0;
}
