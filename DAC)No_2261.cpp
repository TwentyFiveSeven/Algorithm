#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> V,check;
bool cmp(pair<int,int> a, pair<int,int> b){
  if(a.first == b.first) return a.second < b.second;
  return a.first < b.first;
}
int cal(pair<int,int> a, pair<int,int> b){
  return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}
int dac(int left, int right){
  if(left+1 == right) {
    int Lret = V[left].first-V[right].first;
    int Rret = V[left].second-V[right].second;
    return Lret*Lret+Rret*Rret;
  }else if(left+2 == right){
    return min({cal(V[left],V[right]),cal(V[left+1],V[right]),cal(V[left],V[left+1])});
  }
  int mid = (left+right)/2;
  int midval = (V[mid].first+V[mid+1].first)/2;

  int leftval = dac(left,mid);
  int rightval = dac(mid+1,right);
  int ret = min(leftval,rightval);
  int Llocation = mid-1,Rlocation = mid +1;
  for(int i=left;i<=right;i++){
    int tmp = midval - V[i].first;
    if(tmp*tmp < ret){
      check.push_back(make_pair(V[i].first,V[i].second));
    }
  }
  int chSize = check.size();
  for(int i=0;i<chSize;i++){
    for(int j = i+1;j<chSize;j++){
      if((check[i].second - check[j].second)*(check[i].second - check[j].second) < ret){
        int chval = (check[i].second - check[j].second)*(check[i].second - check[j].second)+(check[i].first - check[j].first)*(check[i].first - check[j].first);
        ret = min(ret,chval);
      }
    }
  }
  check.clear();
  return ret;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n,a,b;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    V.push_back(make_pair(a,b));
  }
  sort(V.begin(),V.end(),cmp);
  int ret = dac(0,n-1);
  cout<<ret;
  return 0;
}
