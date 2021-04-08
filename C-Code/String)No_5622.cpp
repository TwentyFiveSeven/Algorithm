#include<iostream>
using namespace std;
int arr[26];
int main(){
  int sum = 0;
  for(int i=0;i<26;i++){
    arr[i] = i/3 +3;
  }
  arr[18] -= 1;arr[21] -= 1; arr[24] -=1;arr[25] -=1;
  string s;
  cin>>s;
  int size = s.size();
  for(int i=0;i<size;i++){
    sum += arr[s[i]-65];
  }
  printf("%d",sum);
  return 0;
}
