#include<iostream>
#include<set>
using namespace std;
set<int> Sx,Sy;

int main(){
  int a,b;
  for(int i=0;i<3;i++){
    scanf("%d %d",&a,&b);
    int count = Sx.count(a);
    if(count){
      auto k = Sx.find(a);
      Sx.erase(k);
    }else
      Sx.insert(a);

    count = Sy.count(b);
    if(count){
      auto m = Sy.find(b);
      Sy.erase(m);
    }else
      Sy.insert(b);
  }
  printf("%d %d",*Sx.begin(),*Sy.begin());
  return 0;
}
