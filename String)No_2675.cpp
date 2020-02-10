#include<iostream>
#include<string>
using namespace std;

int main(){
  int t,r;
  string s;
  scanf("%d",&t);
  while(t--){
    scanf("%d",&r);
    cin>>s;
    int size= s.size();
    for(int i=0;i<size;i++){
      for(int j=0;j<r;j++){
        printf("%c",s[i]);
      }
    }
    printf("\n");
  }
  return 0;
}
