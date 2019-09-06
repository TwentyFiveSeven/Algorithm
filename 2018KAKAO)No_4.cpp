#include<iostream>
#include<algorithm>
#include <string>
#include <vector>

using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    vector<pair<int,int>> tmp;
    int i,j,size,time=0;
    size = food_times.size();
    for(i=0;i<size;i++)
        tmp.push_back(make_pair(food_times[i],i+1));  //각각의 시간과 번호를 입력.
    sort(tmp.begin(),tmp.end());  // 시간이 짧은 순으로 정렬한다.
    int N = size; //size가 --되기 떄문에 저장한다.
    for(i=0;i<N;i++,size--){
        long long round = (long long)(tmp[i].first-time)*size;  //size를 곱하는 이유는
        if(round == 0) continue;  //size를 곱해주면 현재 탐색하는 수를 한바퀴 도는 것을 의미
        if(k >= round){ //k가 더 크다면 몇바퀴 or 몇번 더 이동할 수 있따는 것
            k -= round;
            time = tmp[i].first;
        }else{  //k가 작다면 한바퀴 돌 수 있는 시간이 없다는 것.
            k %= size;
            sort(tmp.begin()+i,tmp.end(),cmp);  //시간순으로 정렬 -> 번호 순으로 정렬
            return tmp[i+k].second; // 몇번째를 다음에 먹을 것인지 선택.
        }
    }
    return -1;
}
