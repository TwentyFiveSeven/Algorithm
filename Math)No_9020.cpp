#include<iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;
vector<pair<int,int>> V;
int check[10001];
int ans=0;
bool Check(int value){
    for(int i=2;i<=sqrt(value);i++){
        if(check[i] ==1) continue;
        for(int j= i+i;j<=value;j+=i){
            if(check[j] ==1)continue;
            check[j] = 1;
            ans--;
        }
    }
    return 1;
}

int main() {
    int t,value;
    scanf("%d",&t);
    Check(10000);
    while(t--){
      scanf("%d",&value);
      for(int i=2;i<value/2+1;i++){
        if(check[i] == 0 && check[value-i]==0){
          V.push_back(make_pair(i,value-i));
        }
      }
      int size = V.size(),a=0,b=0,minus=10001;
      for(int i=0;i<size;i++){
        if(V[i].second-V[i].first< minus){
          a = V[i].first;
          b = V[i].second;
          minus = b-a;
        }
      }
      printf("%d %d\n",a,b);
      while(!V.empty()){V.pop_back();}
    }

    return 0;
}
