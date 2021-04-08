#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
vector<int> V,ans;
int arr[8001];
int main(){
  double tmp = 0;
  int sum = 0,many = 0, interval=0,n,temp,mid=0,save = -4001,max =0;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&temp);
    tmp += temp;
    V.push_back(temp);
    if(temp<0){
      temp = abs(temp)+4000;
    }
    arr[temp]++;
  }
  sort(V.begin(),V.end());
  mid = V[V.size()/2];
  tmp = floor(tmp/n+0.5);
  sum = (int)tmp;
  interval = V.back()-V.front();
  int size = V.size();
  for(int i=0;i<size;i++){
    if(save == V[i])
      continue;
    int val = 0;
    if(V[i]<0)
      val = abs(V[i])+4000;
    else
      val = V[i];
    if(arr[val]>max)
      max = arr[val];
    save = V[i];
  }
  save = -4001;
  for(int i=0;i<size;i++){
    if(save == V[i])
      continue;
    int val = 0;
    if(V[i]<0)
      val = abs(V[i])+4000;
    else
      val = V[i];
    if(arr[val]== max){
      ans.push_back(V[i]);
    }
    save = V[i];
  }
  if(ans.size() == 1)
    many = ans[0];
  else
    many = ans[1];
  printf("%d\n%d\n%d\n%d",sum,mid,many,interval);
  return 0;
}
