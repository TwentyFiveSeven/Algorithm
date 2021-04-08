#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> V;
int main(){
  int a,b,c,i;
  while(1){
    scanf("%d %d %d",&a,&b,&c);
    if(!a||!b||!c) break;
    V.push_back(a);V.push_back(b);V.push_back(c);
    sort(V.begin(),V.end());
    if(V[2]*V[2] == V[1]*V[1]+V[0]*V[0])
      printf("right\n");
    else
      printf("wrong\n");
    while(!V.empty())V.pop_back();
  }
  return 0;
}
