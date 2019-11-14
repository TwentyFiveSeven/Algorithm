#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N;
bool cmp(string a,string b){
    string c = a.substr(N,1);
    string d = b.substr(N,1);
    if(c == d) return a < b;
    else
        return c < d;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    N = n;
    sort(strings.begin(),strings.end(),cmp);
    answer = strings;
    return answer;
}
