#include<iostream>
#include<set>

using namespace std;
set<int> S;
int main(){
  int num,bit=0,n;
  string s;
  scanf("%d",&num);
  for(int i=0;i<num;i++){
    char str[50];
    int tmp=0;
    scanf("%s",str);
    string cmd = str;
    if(cmd == "all"){
      bit = (1<<21) -1;
      continue;
    }else if(cmd == "empty"){
      bit = 0;
      continue;
    }else
      scanf(" %d",&n);
    if(cmd == "add") bit |=(1<<(n-1));
    else if(cmd == "remove") bit &= ~(tmp | (1<<(n-1)));
    else if(cmd == "check") bit>>(n-1) & 1 ? printf("1\n") : printf("0\n");
    else if(cmd == "toggle") bit ^= (1<<(n-1));
  }
  return 0;
}
