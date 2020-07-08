#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
queue<int> Q;
queue<pair<int,int>> V;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0,sum = 0,size = truck_weights.size(),time = 1;
    for(int i=0;i<size;i++){
        Q.push(truck_weights[i]);
    }
    V.push(make_pair(Q.front(),time+bridge_length));
    sum += Q.front();
    Q.pop();
    time++;
    while(!V.empty()){
        int val = V.front().second;
        if(val == time){
            sum -= V.front().first;
            V.pop();
        }
        if(!Q.empty() && sum+Q.front() <= weight){
            V.push(make_pair(Q.front(),time+bridge_length));
            sum += Q.front();
            Q.pop();
        }
        if(Q.empty() && V.empty()) break;
        time++;
    }
    return time;
}
