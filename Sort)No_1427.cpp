#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
  string s;
  getline(cin,s);
  sort(s.begin(),s.end(),greater<char>());
  cout<<s;
  return 0;
}
