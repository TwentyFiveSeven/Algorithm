#include<iostream>
using namespace std;
int check[5] = {0};
int main(){
  string s;
  getline(cin,s);
  int count = 0;
  for(int i=0;i<s.size();i++){
    if(s[i] >='a' && s[i]<='z')
      check[0] =1;
    else if(s[i] >='A' && s[i] <= 'Z')
      check[1] = 1;
    else if(s[i] >='0' && s[i] <= '9')
      check[2] = 1;
    else{
      check[3] = 1;
    }
    count++;
  }
  if(coutn >=10)
    check[4] = 1;
  int answer =0;
  for(int i=0;i<5;i++){
    if(check[i] == 1)
      answer++;
  }
  if(answer == 1) cout<<"LEVEL1";
  else if(answer == 2) cout<<"LEVEL2";
  else if(answer == 3) cout<<"LEVEL3";
  else if(answer == 4) cout<<"LEVEL4";
  else if(answer == 5) cout<<"LEVEL5";
  return 0;
}
