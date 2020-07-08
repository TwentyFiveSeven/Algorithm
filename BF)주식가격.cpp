#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size,0);
    for(int i=0;i<size;i++){
        int count = 0;
        for(int j=i+1;j<size;j++){
            if(prices[i]<=prices[j]){
                answer[i]++;
            }else{
                answer[i]++;
                break;
            }
        }
    }
    return answer;
}
