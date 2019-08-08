#include<iostream>
#include<string>
using namespace std;

string color[10] = {"black","brown","red","orange","yellow","green","blue","violet","grey","white"};
int main(){
  long long int i,sum=0;
  string tmp;

  cin>>tmp;
  for(i=0;i<=9;i++){
    if(tmp == color[i]){
      sum += i*10;
      break;
    }
  }
  cin>>tmp;
  for(i=0;i<=9;i++){
    if(tmp == color[i]){
      sum += i;
      break;
    }
  }
  cin>>tmp;
  for(i=0;i<=9;i++){
    if(tmp == color[i]) break;
  }
  while(i-->0) sum *=10;

  printf("%lld",sum);

  return 0;
}
