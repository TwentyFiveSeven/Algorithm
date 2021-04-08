#include<iostream>
#include<map>
using namespace std;
map<string,int> M;

int main(){
  int t,n,mul = 1;
  char tmp;
  string s;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    scanf("%c",&tmp);
    for(int i=0;i<n;i++){
      getline(cin,s);
      int fd = s.find(" ");
      s = s.substr(fd+1,s.size()-(fd+1));
      if(M.count(s) == -1){
        M.insert(make_pair(s,1));
      }else{
        M[s]++;
      }
    }
    for(auto it = M.begin();it != M.end();it++){
      mul *= (it->second+1);
    }
    printf("%d\n",mul-1);
    M.clear();
    mul = 1;
  }
  return 0;
}
