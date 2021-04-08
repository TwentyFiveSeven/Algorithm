#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<int> V;
    int answer = 0,size =moves.size();
    for(int i=0;i<size;i++){
        int select = -1;
        int num = moves[i]-1;
        for(int j=0;j<board.size();j++){
            if(board[j][num]){
                select = board[j][num];
                board[j][num] =0;
                break;
            }
        }
        if(select == -1) continue;
        if(V.empty())
            V.push_back(select);
        else if(V.back() == select){
            V.pop_back();
            answer +=2;
        }
        else
            V.push_back(select);
    }
    return answer;
}
