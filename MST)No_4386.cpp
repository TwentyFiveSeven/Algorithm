#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
vector<pair<double,pair<int,int>>> K;
vector<pair<double,double>> V;
int par[1001];

int Find(int dot){
  if(par[dot] == dot)
    return dot;
  return par[dot] = Find(par[dot]);
}

int check(int dot1,int dot2){
  int p1 = Find(dot1);
  int p2 = Find(dot2);
  if(p1 == p2) return 0;
  else{
    if(p2 > p1){
      par[p2] = p1;
    }else
      par[p1] = p2;
  }
  return 1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  double a,b,sum = 0;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>a>>b;
    V.push_back(make_pair(a,b));
    par[i] = i;
  }
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      double val = (V[i].first -V[j].first)*(V[i].first -V[j].first) + (V[i].second -V[j].second)*(V[i].second -V[j].second);
      K.push_back(make_pair(sqrt(val),make_pair(i,j)));
    }
  }
  sort(K.begin(),K.end());
  int size = K.size(),count = 0;
  for(int i=0;i<size;i++){
    if(count == N-1) break;
    int dot1 = K[i].second.first;
    int dot2 = K[i].second.second;
    if(check(dot1,dot2)){
      sum += K[i].first;
      count++;
    }
  }
  cout<<round(sum*100)/100 <<'\n';
  return 0;
}
