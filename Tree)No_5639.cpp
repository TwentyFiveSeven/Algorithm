#include<iostream>
#include<vector>
using namespace std;
vector<int> V;
int size;
void postorder(int start,int End){
  int left = start+1;
  while(left <=size-1 && V[left] < V[start]) left++;
  //left = V[start] 보다 큰지점의 시작
  if(start +1 <= left -1)
    postorder(start+1,left-1);
  if(left<=End){
    postorder(left,End);#
  }
  printf("%d\n",V[start]);
}

int main(){
  int a;
  while(scanf("%d",&a) != EOF){
    V.push_back(a);
  }
  size = V.size();
  postorder(0,size-1);
  return 0;
}
