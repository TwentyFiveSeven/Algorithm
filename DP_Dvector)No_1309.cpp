#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> V;
int N;

int main(){
  int i,j,sum=0;
  scanf("%d",&N);
  vector<int> one,two;
  one.push_back(1),two.push_back(1),two.push_back(2);
  V.push_back(one),V.push_back(two);
  for(i=1;i<=N-1;i++){
    vector<int> one;
    one.push_back(1);
    for(j=1;j<V[1].size();j++){
      one.push_back((V[0][j-1]+V[1][j-1]+V[1][j])%9901);
    }
    one.push_back(2);
    // reverse(V.begin(),V.end());
    V.erase(V.begin());
    V.push_back(one);
  }
  for(i=0;i<V[1].size();i++)
    sum=(sum + V[1][i])%9901;
  printf("%d",sum);
  return 0;
}
