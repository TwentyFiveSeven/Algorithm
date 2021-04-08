#include<iostream>
#include<string>
using namespace std;

int arr[4001][4001];
char col[4001],row[4001];
int Csize,Rsize,maxN;
void LCS(){
  int i,j;
  for(i=1;i<=Rsize;i++){
    for(j=1;j<=Csize;j++){
      if(col[j]==row[i]) arr[i][j] = arr[i-1][j-1]+1;
      else arr[i][j] = 0;

      if(arr[i][j]>maxN) maxN = arr[i][j];
    }
  }
}

int main(){
  int i,j;
  string input;
  cin>>input;Csize = input.size();
  for(i=0;i<input.size();i++) col[i+1] = input.at(i);
  cin>>input;Rsize = input.size();
  for(i=0;i<input.size();i++) row[i+1] = input.at(i);

  LCS();
  printf("%d",maxN);
  return 0;

}
