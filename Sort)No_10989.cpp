#include<iostream>
#include<map>
#include<set>
using namespace std;
set<int> V;
int arr[10001];
map<int,int> m;
int main(){
  ios_base::sync_with_stdio(false);
  int n,tmp;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>tmp;
    V.insert(tmp);
    arr[tmp]++;
  }
  for(auto it = V.begin();it !=V.end();it++){
    int val = *it;
    int size = arr[val];
    for(int i=0;i<size;i++){
      cout << val << '\n';
    }
  }
  return 0;
}
