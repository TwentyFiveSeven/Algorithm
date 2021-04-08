#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N,Max;
vector<pair<int,int>> P;
vector<int> V,ans,temp;
bool cmp(pair<int,int> a,pair<int,int> b){
  return a.first < b.first;
}

bool cmp2(pair<int,int> a,pair<int,int> b){
  return a.second > b.second;
}

int find(int x){
  // printf("in %d\n",x);
  vector<int> save;
  save.push_back(1);
  save.push_back(2);
  for(int i=x+1;i<N;i++){
    auto iter = lower_bound(V.begin(),V.end(),P[i].second);
    int idx = iter - V.begin();
    if(idx == V.size()){
      V.push_back(P[i].second);
    }else{
      auto endN = save.end();
      save.erase(save.begin(),endN);
      save.assign(V.begin(),V.end());
      V.erase(iter,V.end());
      V.push_back(P[i].second);
      find(i);
      V.assign(save.begin(),save.end());
      find(i);
      return 0;
    }
  }
  printf("\n");
  if(V.size()>Max){
    Max = V.size();
    ans.assign(V.begin(),V.end());
  }
}

int main(){
  int i,j,a,b;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d %d",&a,&b);
    P.push_back(make_pair(a,b));
  }
  sort(P.begin(),P.end(),cmp);
  find(-1);
  printf("%d\n",Max);
  for(i=0;i<ans.size();i++){
    printf("%d ",ans[i]);
  }
  printf("\n");
  for(i=0;i<ans.size();i++){
    auto idx = lower_bound(P.begin(),P.end(),pair<int,int>(1,ans[i]),cmp2);
    P.erase(idx);
  }
  for(i=0;i<P.size();i++){
    printf("%d ",P[i].first);
  }
  // for(i=0;i<N;i++){
  //   int idx = lower_bound(V.begin(),V.end(),P[i].second) - V.begin();
  //   if(idx == V.size()){
  //     // printf("input : %d, %d\n",P[i].first,P[i].second);
  //     temp.push_back(P[i].first);
  //     V.push_back(P[i].second);
  //   }
  //   else{
  //     // printf("out : %d, %d\n",P[idx].first,P[idx].second);
  //     if(V[idx]>P[i].second){
  //       ans.push_back(P[i].first);
  //     }else
  //       V[idx] = P[i].second;
  //       temp[idx] = P[i].first;
  //       ans.push_back(temp[idx]);
  //   }
  // }
  // for(i=0;i<temp.size();i++){
  //   printf("%d ",temp[i]);
  // }
  // printf("\n");
  // sort(ans.begin(),ans.end());
  // printf("%d\n",N-V.size());
  // for(i=0;i<ans.size();i++){
  //   printf("%d\n",ans[i]);
  // }
  return 0;
}
