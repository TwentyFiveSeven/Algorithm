#include<iostream>
#include<vector>
using namespace std;
int N,M,CCTV=0,Min = 2000000001;
vector<pair<int,int>> V;

void East(int x,int y, vector<vector<int>> &K,int &ANS){
  for(int i=y+1;i<M;i++){
    if(K[x][i] == 6) break;
    else if(K[x][i] != 0) continue;
    K[x][i] = 7;
    ANS--;
  }
}

void West(int x,int y, vector<vector<int>> &K,int &ANS){
  for(int i=y-1;i>=0;i--){
    if(K[x][i] == 6) break;
    else if(K[x][i] != 0) continue;
    K[x][i] = 7;
    ANS--;
  }
}

void South(int x,int y, vector<vector<int>> &K,int &ANS){
  for(int i=x+1;i<N;i++){
    if(K[i][y] == 6) break;
    else if(K[i][y] != 0) continue;
    K[i][y] = 7;
    ANS--;
  }
}

void North(int x,int y, vector<vector<int>> &K,int &ANS){
  for(int i=x-1;i>=0;i--){
    if(K[i][y] == 6) break;
    else if(K[i][y] != 0) continue;
    K[i][y] = 7;
    ANS--;
  }
}
void one(int x,int y, int dir, vector<vector<int>> &K,int &ANS){
  if(dir == 1)
    East(x,y,K,ANS);
  else if(dir == 2)
    South(x,y,K,ANS);
  else if(dir == 3)
    West(x,y,K,ANS);
  else if(dir == 4)
    North(x,y,K,ANS);
}

void two(int x,int y, int dir, vector<vector<int>> &K,int &ANS){
  if(dir == 1 || dir == 3){
    East(x,y,K,ANS);
    West(x,y,K,ANS);
  }else{
    South(x,y,K,ANS);
    North(x,y,K,ANS);
  }
}

void three(int x,int y, int dir, vector<vector<int>> &K,int &ANS){
  if(dir == 1){
    North(x,y,K,ANS);
    East(x,y,K,ANS);
  }else if(dir == 2){
    East(x,y,K,ANS);
    South(x,y,K,ANS);
  }else if(dir == 3){
    South(x,y,K,ANS);
    West(x,y,K,ANS);
  }else{
    West(x,y,K,ANS);
    North(x,y,K,ANS);
  }
}

void four(int x,int y, int dir, vector<vector<int>> &K,int &ANS){
  if(dir == 1){
    West(x,y,K,ANS);
    North(x,y,K,ANS);
    East(x,y,K,ANS);
  }else if(dir == 2){
    North(x,y,K,ANS);
    East(x,y,K,ANS);
    South(x,y,K,ANS);
  }else if(dir == 3){
    East(x,y,K,ANS);
    South(x,y,K,ANS);
    West(x,y,K,ANS);
  }else{
    South(x,y,K,ANS);
    West(x,y,K,ANS);
    North(x,y,K,ANS);
  }
}

void five(int x,int y, int dir, vector<vector<int>> &K,int &ANS){
  North(x,y,K,ANS);
  East(x,y,K,ANS);
  South(x,y,K,ANS);
  West(x,y,K,ANS);
}

void Kinds(int x, int y, int Num,int dir,vector<vector<int>> &K,int &ANS){
  if(Num == 1)
    one(x,y,dir,K,ANS);
  else if(Num == 2)
    two(x,y,dir,K,ANS);
  else if(Num == 3)
    three(x,y,dir,K,ANS);
  else if(Num == 4)
    four(x,y,dir,K,ANS);
  else
    five(x,y,dir,K,ANS);
}

void dfs(int depth, vector<vector<int>> Map,int ANS){
  if(depth == CCTV){
    if(Min> ANS) Min = ANS;
    return;
  }
  vector<vector<int>> temp(8,vector<int>(8));
  temp = Map;
  int TANS = ANS;
  int x = V[depth].first;
  int y = V[depth].second;
  int val = Map[x][y];
  for(int i=1;i<=4;i++){
    Kinds(x,y,val,i,temp,TANS);
    dfs(depth+1,temp,TANS);
    temp = Map;
    TANS = ANS;
  }
}


int main(){
  vector<vector<int>> Map(8,vector<int>(8));
  cin>>N>>M;
  int ANS = N*M;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin>>Map[i][j];
      if(Map[i][j]>0 && Map[i][j]<6){
        V.push_back(make_pair(i,j));
        CCTV++;
        ANS--;
      }else if(Map[i][j] == 6) ANS--;
    }
  }
  if(CCTV ==0){
    cout<<ANS;
    return 0;
  }
  dfs(0,Map,ANS);
  cout<<Min;
  return 0;
}
