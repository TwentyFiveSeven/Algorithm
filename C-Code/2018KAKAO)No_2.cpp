#include<iostream>
#include <string>
#include<queue>
#include <vector>

using namespace std;
struct cmp{
    bool operator()(pair<int,double> a,pair<int,double> b){
        if(a.second != b.second)
            return a.second < b.second;
        else
            return a.first > b.first;
    }
};
priority_queue<pair<int,double>,vector<pair<int,double>>,cmp> pq;
int arr[502];

vector<int> solution(int N, vector<int> stages) {
    fill_n(arr,502,0);
    double sum=0;
    vector<int> answer;
    for(int i=0;i<stages.size();i++){
        arr[stages[i]]++; //N+1부터 몇개있는지 count 한다.
    }
    sum = (double)arr[N+1]; //가장처음 N+1값을 더한다.
    for(int i=N;i>=1;i--){  //N부터 차례대로 구해나간다.
        sum += (double)arr[i];
        if(sum ==0){  //분모가 0인 경우에는 0값을 입력한다.
            pq.push(make_pair(i,0));
            continue;
        }
        pq.push(make_pair(i,(double)arr[i]/sum)); //순서대로 입력.
    }
    while(!pq.empty()){
        answer.push_back(pq.top().first); //pq의 사이즈순으로 입력한다.
        pq.pop();
    }
    return answer;
}
