#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    int size = commands.size(),Asize = array.size();
    for(int i=0;i<size;i++){
        vector<int> V = array;
        for(int j=0;j<commands[i][0]-1;j++)
            V.erase(V.begin());
        for(int j=0;j<Asize - commands[i][1];j++)
            V.pop_back();
        sort(V.begin(),V.end());
        answer.push_back(V[commands[i][2]-1]);
    }
    return answer;
}
