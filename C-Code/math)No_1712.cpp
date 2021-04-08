#include<iostream>
using namespace std;

int main(){
  long long int a,b,c,sum,ans,count;

 scanf("%lld %lld %lld",&a,&b,&c);
 if(b>=c){
   printf("-1");
   return 0;
 }
 ans = c-b;
 ans = a/ans +1;
 printf("%lld",ans);
 return 0;
}
