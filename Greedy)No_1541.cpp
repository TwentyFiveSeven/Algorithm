#include<iostream>
#include<string.h>
#include<vector>
#include<stdlib.h>
using namespace std;
vector<int> V;
vector<char> C;

int main(){
  string s,temp;
  getline(cin,s);
  int sum =0,flag = 0;
  s = '+'+s;
  C.push_back('+');
  int size = s.size();

  for(int i=1;i<size;i++){
    if(s[i] == '+'){
      if(flag == 1)
        C.push_back('-');
      else
        C.push_back('+');
      V.push_back(atoi(temp.c_str()));
      temp = "";
    }else if(s[i] == '-'){
      flag = 1;
      int end = s.find('-',i+1);
      C.push_back('-');
      V.push_back(atoi(temp.c_str()));
      temp = "";
    }else{
      temp += s[i];
    }
    if(i == size-1)
      V.push_back(atoi(temp.c_str()));
  }
  for(int i=0;i<C.size();i++){
    if(C[i] == '+')
      sum += V[i];
    else
      sum -= V[i];
  }
  printf("%d",sum);
  return 0;
}
