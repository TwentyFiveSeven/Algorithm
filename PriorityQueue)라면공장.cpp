#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> Q;
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    dates.push_back(k);
    int answer = 0,size = dates.size(),sum = stock;
    for(int i=0;i<size;i++){
        if(sum > k) break;
        if(sum >= dates[i])
            Q.push(supplies[i]);
        else{
            while(!Q.empty() && sum < dates[i]){
                sum += Q.top();
                Q.pop();
                answer++;
            }
            Q.push(supplies[i]);
        }
    }
    return answer;
}
