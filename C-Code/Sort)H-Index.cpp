#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0,size = citations.size();
    sort(citations.begin(),citations.end());
    for(int i=0;i<10001;i++){
        int findV = -1;
        for(int j=0;j<size;j++){
            if(i<=citations[j]){
                findV = j;
                break;
            }
        }
        if(findV != -1){
            if(size-findV >= i)
                if(i > answer)
                    answer = i;
        }
    }
    return answer;
}
