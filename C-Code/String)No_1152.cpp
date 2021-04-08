#include<iostream>
using namespace std;

int main(){
  string s;
  getline(cin,s);
  int count=1,size = s.size();
  if(size == 1 && s[0] ==' '){
    printf("0");
    return 0;
  }
  for(int i=0;i<size;i++){
    if(s[i] == ' ' && i-1>=0 && i+1<size && s[i-1] !=' ' && s[i+1] != ' '){
      count++;
    }
  }
  printf("%d",count);
  return 0;
}
