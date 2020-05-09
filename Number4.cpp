
#include <string>
#include <vector>
#include <queue>
#include<iostream>
#include<algorithm>

using namespace std;
vector<vector<int>> V = {{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0}};
int Min=2000000000,arr[25][25],check[25][25];
int N,xi[4]= {0,1,-1,0},yi[4] = {1,0,0,-1};
void dfs(int x,int y, int dir, int st, int cur){
    if(x == N-1 && y == N-1){
        cout<<"st : "<<st<<", cur : "<<cur<<'\n';
        Min = min(Min,st*100+cur*500);
        return;
    }
    if(check[x][y] == 1 )return;
    check[x][y] = 1;
    cout<<"x : "<<x<<", y : "<<y<<'\n';
    for(int i=0;i<4;i++){
        int nx = x+xi[i];
        int ny = y+yi[i];
        if(nx>=0&&nx<N&&ny>=0&&ny<N&&arr[nx][ny] ==0){
            if(dir == -1 || i == dir){
                dfs(nx,ny,i,st+1,cur);
                // check[nx][ny] = 0;
            }else{
                dfs(nx,ny,i,st+1,cur+1);
                // check[nx][ny] = 0;
            }
        }
    }
}
int solution(vector<vector<int>> board) {
    N = board.size();
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            arr[i][j] = board[i][j];
        }
    }
    int answer = 0;
    dfs(0,0,-1,0,0);
    answer = Min;
    return answer;
}

int main(){
  return solution(V);
}
