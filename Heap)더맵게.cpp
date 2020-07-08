#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long>> Q;
int solution(vector<int> scoville, int K) {
    int answer = 0,size = scoville.size();
    for(int i=0;i<size;i++){
        Q.push(scoville[i]);
    }
    while(Q.top() < K){
        long long val = Q.top();
        Q.pop();
        if(Q.empty()) return -1;
        long long Plus = Q.top();
        Q.pop();
        long long sum = val + Plus*2;
        Q.push(sum);
        answer++;
    }
    return answer;
}
