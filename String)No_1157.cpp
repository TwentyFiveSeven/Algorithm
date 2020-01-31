#include<iostream>
#include<string>
#include<vector>
using namespace std;
int arr[26];

int main(){
  int count = 0,max = -1;
  string s;
  cin>>s;
  int size = s.size();
  for(int i=0;i<size;i++){
    int c = s[i];
    if(c < 'a')
      c -= 65;
    else
      c -= 97;
    arr[c]++;
  }
  for(int i=0;i<26;i++){
    if(arr[i] > max){
      max = arr[i];
      count = i;
    }else if(arr[i] == max){
      count = -1;
    }
  }
  if(count == -1)
    printf("?");
  else
    printf("%c",count+65);
  return 0;
}
