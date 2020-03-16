#include<iostream>
#include<vector>
using namespace std;
vector<pair<int,int>> V;
int N;
int main(){
  int val = -1;
  scanf("%d",&N);
  V.push_back(make_pair(100,100));
  V.push_back(make_pair(0,0));
  V.push_back(make_pair(1,2));
  V.push_back(make_pair(1,3));
  for(int i=4;i<=N;i++){
    val = -1;
    int Max = V[i-1].first;
    if(!(i%3) && Max > V[i/3].first){
      Max = V[i/3].first;
      val = 3;
    }
    if(!(i%2) && Max > V[i/2].first){
      Max = V[i/2].first;
      val = 2;
    }
    V.push_back(make_pair(Max+1,val));
  }
  int div = V[N].second;
  int value = N;
  printf("%d\n",V[N].first);
  while(div != 0 ){
    printf("%d ",value);
    if(div == -1){
      value = value -1;
      div = V[value].second;
    }else{
      value = value/div;
      div = V[value].second;
    }
  }
  printf("1");
  return 0;
}
