#include<iostream>
#define CY 360000
using namespace std;
int N;
int arr[720001],sec[360001],pi[360001];

void getpi(){
  int j=0;
  for(int i=1;i<CY;i++){
    while(j>0&&sec[i] != sec[j])
      j = pi[j-1];
    if(sec[i] == sec[j])
      pi[i] =++j;
  }
}

void KMP(){
  bool f = false;
  int j=0;
  for(int i=0;i<CY*2;i++){
    while(j>0 && arr[i] != sec[j])
      j = pi[j-1];
    if(arr[i] == sec[j]){
      if(j == CY-1){
        cout<<"possible";
        return;
      }else{
        j++;
      }
    }
  }
  cout<<"impossible";
}

int main(){
  int a;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>a;
    arr[a] = 1;
    arr[a + CY] = 1;
  }
  for(int i=0;i<N;i++){
    cin>>a;
    sec[a] = 1;
  }
  getpi();
  KMP();
  return 0;
}
