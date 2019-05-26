#include<iostream>
using namespace std;

int Xarr[100001];
int Yarr[100001];
int n;

int main(){
  int min=100001,max=-1,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
      scanf("%d %d",&Xarr[i],&Yarr[i]);
    }

    for(i=1;i<=n;i++){
      if(Xarr[i]>max){
        max = Xarr[i];
      }
      if(min>Yarr[i]){
        min = Yarr[i];
      }
    }
    if(max-min<0)
      printf("0");
    else
      printf("%d",max-min);

    return 0;
}
