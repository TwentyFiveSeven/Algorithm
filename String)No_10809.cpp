#include<iostream>
#include<string.h>

using namespace std;
int arr[26];

int main(){
  string s;
  for(int i=0;i<26;i++)
    arr[i] = -1;
  cin>>s;
  int size = s.size(),value = 0;
  for(int i=0;i<size;i++){
    value = s[i]-'a';
    if(arr[value] == -1)
      arr[value] = i;
  }
  for(int i=0;i<26;i++)
    printf("%d ",arr[i]);
  return 0;
}
