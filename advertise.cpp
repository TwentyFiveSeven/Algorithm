#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){
  long long int size,i;
  int scount=0,save=0,ans=1;
  char p;

  scanf("%lld",&size);
  scanf("%c",&p);
  char *s = new char[size];
  for(i=0; i<size;i++){
    scanf("%c",&p);
    if(s[scount]==p){
      s[i]=p;
      ++scount;
      scount =scount%ans;
      save++;
    }else{
      if(i!=0){ans++;}
      if(p!=s[0]||i!=size-1){ans = save+ans;}
      s[i]=p;
      scount=0;
      save =0;
    }
    printf("%d %d %d\n",scount,ans,save);
  }
  printf("%d\n",ans);

}
