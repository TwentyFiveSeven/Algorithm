#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 1,size = people.size(),sum=0,person = 0;
    sort(people.begin(),people.end(),greater<int>());
    for(int i=0;i<people.size();i++){
        if(sum + people[i] > limit || person ==2){
            sum = people[i];
            answer++;
            person = 1;
            if(i != people.size()-1)
                if(sum + people.back() <=limit){
                    sum += people.back();
                    people.pop_back();
                    person++;
                }
        }else if(sum + people[i] <= limit){
            sum += people[i];
            person++;
            if(sum + people.back() <= limit){
                sum += people.back();
                people.pop_back();
                person++;
            }
        }
    }
    return answer;
}
