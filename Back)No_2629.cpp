#include<iostream>
#include<set>
using namespace std;

int sinkerN,sinker[31],marbleN,marble[8];
set<int> s;
set<int>::iterator Titer;
void findPlus(int start,int sum,int minus){
  int i;
  for(i=start;i<=sinkerN;i++){
    sum += sinker[i];
    minus -= sinker[sinkerN-i+1];
    s.insert(sum);
    if(minus>0) s.insert(minus);
    findPlus(i+1,sum,minus);
    sum -= sinker[i];
    minus += sinker[sinkerN-i+1];
    findPlus(i+1,sum,minus);
  }
}
int main(){
  set<int>::iterator iter;
  int i,sum=0,flag=0,value=0;
  scanf("%d",&sinkerN);
  for(i=1;i<=sinkerN;i++){
    scanf("%d",&sinker[i]);
    sum += sinker[i];
  }
  scanf("%d",&marbleN);
  for(i=1;i<=marbleN;i++){
    scanf("%d",&marble[i]);
  }
  findPlus(1,0,sinker[sinkerN]);
  s.erase(0);

  for(i=1;i<=marbleN;i++){
    flag=0;
    for(iter = s.begin();iter!=s.end();iter++){
      value = *iter;
      if(value == marble[i]){
        printf("Y ");
        flag =1;
      }
    }
    if(flag==0) printf("N ");
  }
  return 0;
}
