#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<vector<string>> arr;
char col[1001],row[1001];
int Csize,Rsize;
void LCS(){
  int i,j;
  for(i=1;i<=Rsize;i++){
    for(j=1;j<=Csize;j++){
      if(col[j]==row[i]){
        arr[i][j] = arr[i-1][j-1]+row[i];
      }else{
        if(arr[i-1][j].size()>arr[i][j-1].size()){
          arr[i][j] = arr[i-1][j];
        }else{
          arr[i][j] = arr[i][j-1];
        }
      }
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

  for(i=0;i<Rsize+1;i++){
    vector<string> element(Csize+1);
    arr.push_back(element);
  }

  LCS();
  cout<<arr[Rsize][Csize].size()<<endl;
  cout<<arr[Rsize][Csize];
  return 0;

}
