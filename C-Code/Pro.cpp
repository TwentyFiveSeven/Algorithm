#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>> temp,F,S,temp1;
int main(){
  int N,a,b,save = -1;
  for(int i=0;i<N;i++){
    cin>>a>>b;
    temp.push_back(make_pair(b,a)); //자식,부모
  }
  sort(temp.begin(),temp.end());
  for(int i=0;i<N-1;i++){
    if(temp[i].first == temp[i+1].first)
      save = i;
      break;
  }
  F = temp;
  F.erase(F.begin()+save);
  S.erase(S.begin()+save+1);


}
