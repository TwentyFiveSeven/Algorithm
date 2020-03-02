#include<iostream>
#include<queue>
using namespace std;
queue<int> Q;
int main(){
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    Q.push(i);
  }
  while(1){
    if(Q.size() == 1){
      printf("%d",Q.back());
      return 0;
    }
    Q.pop();
    Q.push(Q.front());
    Q.pop();
  }
  return 0;
}
