#include <string>
#include <vector>
#include <map>
using namespace std;
map<long long, long long> M;
long long Find(long long c){
    if(!M[c]) return c;
    return M[c] = Find(M[c]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(int i=0;i<room_number.size();i++){
        long long val = room_number[i];
        if(!M[val]){
            M[val] = Find(val+1);
            answer.push_back(val);
        }else{
            long long FV = Find(M[val]);
            M[FV] = Find(FV+1);
            answer.push_back(FV);
        }
    }
    return answer;
}
