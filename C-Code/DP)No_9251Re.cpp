#include<iostream>
using namespace std;
string arr1[1001],arr2[1001];
int Arr[1001][1001];
int main(){
  int Asize,Bsize;
  string a,b;
  getline(cin,a);
  getline(cin,b);
  Asize = a.size(); Bsize = b.size();
  for(int i = 1;i<=Asize;i++){
    arr1[i] = a[i-1];
  }
  for(int i=1;i<=Bsize;i++){
    arr2[i] = b[i-1];
  }
  for(int i=1;i<=Bsize;i++){
    for(int j=1 ;j<=Asize;j++){
      if(arr1[j] == arr2[i]){
        Arr[i][j] = Arr[i-1][j-1]+1;
      }else{
        Arr[i][j] = max(Arr[i][j-1],Arr[i-1][j]);
      }
    }
  }
  printf("%d",Arr[Bsize][Asize]);
  return 0;
}
