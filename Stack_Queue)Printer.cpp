#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0,max = 0,size = priorities.size(),count=size-1,i;
    vector<pair<int,int>> V;
    for(i=0;i<size;i++){
        V.push_back(make_pair(priorities[i],i));
    }
    i=0;
    sort(priorities.begin(),priorities.end());
    while(!V.empty()){
        if(priorities[count] == V.front().first){
            count--;
            if(V.front().second == location)
                return i+1;
            V.erase(V.begin());
            i++;
        }else{
            V.push_back(make_pair(V.front().first,V.front().second));
            V.erase(V.begin());
        }

    }
    return answer;
}
