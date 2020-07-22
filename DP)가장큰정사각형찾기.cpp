#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0,sizeR = board.size(),sizeC = board[0].size();
    for(int i=1;i<sizeR;i++){
        for(int j=1; j<sizeC;j++){
            if(board[i][j]){
                board[i][j] = min({board[i-1][j],board[i][j-1],board[i-1][j-1]}) + board[i][j];
                if(board[i][j] > answer) answer = board[i][j];
                }
        }
    }
    if(!answer){
        for(int i=0;i<sizeR;i++)
            if(board[i][0]) answer = 1;
        for(int i=0;i<sizeC;i++)
            if(board[0][i]) answer = 1;
    }
    return answer*answer;
}
