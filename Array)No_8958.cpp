#include<iostream>
using namespace std;

int main(){
  string s;
  int n,size;
  char a;
  scanf("%d",&n);
  scanf("%c",&a);
  for(int i=0;i<n;i++){
    getline(cin,s);
    size = s.size();
    int count = 1,sum = 0;
    for(int j=0;j<size;j++){
      if(s[j] == 'O'){
        sum += count;
        count++;
      }else{
        count = 1;
      }
    }
    printf("%d\n",sum);
  }
  return 0;
}
