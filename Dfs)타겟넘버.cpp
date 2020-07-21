#include <string>
#include <vector>

using namespace std;
int check = 0,T=0;
vector<int> V;
void dfs(int now, int val,int depth, int limit){
    if(depth == limit){
        if(val == T)
            check++;
        return;
    }
    dfs(now+1,val+V[now],depth+1,limit);
    dfs(now+1,val-V[now],depth+1,limit);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    V = numbers;
    T = target;
    dfs(0,0,0,numbers.size());
    answer = check;
    return answer;
}
