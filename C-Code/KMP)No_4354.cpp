#include<iostream>
#include<vector>
using namespace std;

int Fail(string s){
  int size = s.size(),j=0;
  vector<int> pi(size,0);
  for(int i=1;i<size;i++){
    while(j>0 && s[i] != s[j])
      j = pi[j-1];
    if(s[i] == s[j])
      pi[i] = ++j;
  }
  return pi[size-1];
}

// int KMP(string s,string p){
//   int Ssize = s.size(),Psize = p.size(),j=0,count=0;
//   vector<int> pi = fail(p);
//   for(int i=0;i<Ssize;i++){
//     while(j>0 && s[i] != p[j])
//       j = pi[j-1];
//     if(s[i] == p[j]){
//       if(j == Psize-1){
//         count++;
//         j = pi[j];
//       }else{
//         j++;
//       }
//     }else if(count && s[i] != p[j]){
//       return 1;
//     }
//   }
//   return count;
// }

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  while(1){
    cin>>s;
    if(s.compare(".") == 0) break;
    int size = s.size();
    int limit = size/2 +size%2;
    int val = Fail(s);
    if(size%(size-val) != 0){
      cout<<"1"<<'\n';
    }else{
      val = size/(size-val);
      cout<<val<<'\n';
    }
    // for(int i=1;i<=size/2;i++){
    //   string temp = s.substr(0,i);
    //   val = max(val,KMP(s,temp));
    // }
    // cout<<val<<'\n';
  }
  return 0;
}
