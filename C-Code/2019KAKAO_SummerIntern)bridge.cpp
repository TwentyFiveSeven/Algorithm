#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
map<int,pair<int,int>> M;

int Find(int c){
    if(!M[c].second) return c;
    return M[c].second = Find(M[c].second);
}

int solution(vector<int> stones, int k) {
    int answer = 0,size = stones.size();
    vector<pair<int,int>> V;
    for(int i=0;i<stones.size();i++){
        V.push_back(make_pair(stones[i],i+1));
    }
    sort(V.begin(), V.end());
    for(int i=0;i<size;i++){
        int val = V[i].second;
        if(!M[val].second){
            int temp = 0;
            if(M[val-1].second)
                temp = M[val-1].first;
            M[val].first = 1+temp;
            int ans = M[val].first,par;
            if(M[val+1].second){
                par = Find(val+1)-1;
                M[val].second = par;
                ans += M[par].first;
                M[par].first = ans;
            }else{
                M[val].second = val+1;
            }
            if(ans >=k){
                answer = stones[val-1];
                return answer;
            }

        }
    }
    return answer;
}
