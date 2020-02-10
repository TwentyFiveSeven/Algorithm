#include<iostream>
using namespace std;

int main(){
  string s;
  int count =0,size;
  cin>>s;
  size = s.size();
  for(int i=0;i<size;i++){
    if(s[i] == '='){
      if(i-1>=0&&s[i-1] == 'z'){
        if(i-2>=0&&s[i-2] == 'd'){
          count -= 2;
        }else
          count -= 1;
      }else if(i-1>=0&&(s[i-1] == 'c'||s[i-1] == 's'))
        count -=1;
    }else if(s[i] == '-'){
      if(i-1>=0 && (s[i-1] == 'c'||s[i-1]=='d'))
        count -=1;
    }else if(s[i] == 'j'){
      if(i-1>=0 && (s[i-1] == 'l'||s[i-1] == 'n'))
        count -=1;
    }
    count++;
  }
  printf("%d",count);
  return 0;
}
