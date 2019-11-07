#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> V = {{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}};
int arr[3];
vector<int> solution(vector<int> answers) {
    int size = answers.size();
    vector<pair<int,int>> tmp;
    for(int i=0;i<3;i++)
        tmp.push_back(make_pair(0,i));
    vector<int> answer;
    for(int i=0; i<size;i++){
        if(answers[i] == V[0][i%5])
            tmp[0].first++;
        if(answers[i] == V[1][i%8])
            tmp[1].first++;
        if(answers[i] == V[2][i%10])
            tmp[2].first++;
    }
    sort(tmp.begin(),tmp.end(),greater<pair<int,int>>());
    answer.push_back(tmp[0].second+1);
    for(int i=1;i<3;i++){
        if(tmp[0].first == tmp[i].first)
            answer.push_back(tmp[i].second+1);
    }
    sort(answer.begin(),answer.end());
    return answer;
}
