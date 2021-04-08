#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0,size = land.size();
    for(int i=1;i<size;i++){
        land[i][0] = max({land[i-1][1],land[i-1][2],land[i-1][3]}) + land[i][0];
        land[i][1] = max({land[i-1][0],land[i-1][2],land[i-1][3]}) + land[i][1];
        land[i][2] = max({land[i-1][1],land[i-1][0],land[i-1][3]}) + land[i][2];
        land[i][3] = max({land[i-1][1],land[i-1][2],land[i-1][0]}) + land[i][3];
    }
    answer = max({land[size-1][0],land[size-1][1],land[size-1][2],land[size-1][3]});
    return answer;
}
