#include<iostream>
#include<vector>
using namespace std;
int arr[26];
vector<string> S;
int main(){
  int n,count = 0;
  string s;
  scanf("%d",&n);
  count = n;
  for(int i=0;i<n;i++){
    cin>>s;
    S.push_back(s);
  }
  for(int i=0;i<n;i++){
    int size = S[i].size();
    arr[S[i][0]-97]++;
    for(int j=1;j<size;j++){
      if(S[i][j-1] != S[i][j] && arr[S[i][j]-97]!=0){
        count--;
        break;
      }
      arr[S[i][j]-97]++;
    }
    for(int j=0;j<26;j++){
      arr[j] = 0;
    }
  }
  printf("%d",count);
  return 0;
}
