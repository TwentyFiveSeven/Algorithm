#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> K;
vector<vector<int>> V;
int N;

int main(){
  int i,j,input,save,Max=0;
  scanf("%d",&N);
  // for(i=0;i<N;i++){
  //   vector<int> tmp1(N-i-1);
  //   V.push_back(tmp1);
  // }
  for(i=0;i<N;i++){
    scanf("%d",&input);
    K.push_back(input);
  }
  for(i=0;i<K.size();i++){
    vector<int> P;
    P.push_back(K[i]);
    for(j=i+1;j<K.size();j++){
      auto tmp = lower_bound(P.begin(),P.end(),K[j]);
      int temp = tmp -P.begin();
      if(temp == P.size()){
        P.push_back(K[j]);
      }else{
        P[temp] = K[j];
      }
      for(int k=0;k<P.size();k++){
        printf("%d ",P[k]);
      }
      printf("\n");
    }
    V.push_back(P);
    if(P.size()>Max){
      Max = P.size();
      save = i;
    }
    if(Max>N-i-1) break;
  }
  printf("%d\n",Max);
  for(int k=0;k<V[save].size();k++){
    printf("%d ",V[save][k]);
  }
  return 0;
}
