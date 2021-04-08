#include<iostream>
#include<string>
using namespace std;

int arr[1001][1001];
char col[1001],row[1001];
int Csize,Rsize;
void LCS(){
  int i,j;
  for(i=1;i<=Rsize;i++){
    for(j=1;j<=Csize;j++){
      if(col[j]==row[i]) arr[i][j] = arr[i-1][j-1]+1;
      else arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
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
  printf("%d",arr[Rsize][Csize]);
  return 0;

}
