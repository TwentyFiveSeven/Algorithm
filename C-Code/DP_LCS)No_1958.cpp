#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[101][101][101],Max;
vector<string> V;

bool cmp(string a, string b){
  return a.size() > b.size(); //내림차순
}

int LCS(string a,string b,string c){
  int sizeA = a.size(),sizeB = b.size(),sizeC = c.size();
  for(int i=1;i<=sizeA;i++){
    for(int j=1;j<=sizeB;j++){
      for(int k=1;k<=sizeC;k++){
        if(a[i-1] == b[j-1] && b[j-1] == c[k-1]) arr[i][j][k] = arr[i-1][j-1][k-1]+1;
        else
          arr[i][j][k] = max({arr[i-1][j][k],arr[i][j][k-1],arr[i][j-1][k]});
        if(arr[i][j][k]>Max){ Max = arr[i][j][k];
        }
      }
    }
  }
}


int main(){
  int i,j,temp1,temp2;
  string temp;
  for(i=0;i<3;i++){
    cin>>temp;
    V.push_back(temp);
  }
  LCS(V[0],V[1],V[2]);
  printf("%d",Max);
  return 0;
}
