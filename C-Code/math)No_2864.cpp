#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int main(){
  int sum=0,i;
  string a,b;
  cin>>a>>b;
  for(i=0;i<a.size();i++){
    if(a.at(i) == '6') a.at(i) = '5';
  }
  for(i=0;i<b.size();i++){
    if(b.at(i) == '6') b.at(i) = '5';
  }
  printf("%d",atoi(a.c_str())+atoi(b.c_str()));
  for(i=0;i<a.size();i++){
    if(a.at(i) == '5') a.at(i) = '6';
  }
  for(i=0;i<b.size();i++){
    if(b.at(i) == '5') b.at(i) = '6';
  }
  printf(" %d",atoi(a.c_str())+atoi(b.c_str()));
  return 0;
}
