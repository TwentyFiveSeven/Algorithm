#include<iostream>
#include<set>
using namespace std;
set<int> S;
int main(){
  int value,i;
  for(i=0;i<10;i++){
    scanf("%d",&value);
    S.insert(value%42);
  }
  printf("%d",S.size());
  return 0;
}
