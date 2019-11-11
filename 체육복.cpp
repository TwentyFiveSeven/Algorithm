#include <string>
#include <vector>

using namespace std;
int arr[30];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(int i=0;i<n;i++){
        arr[i] = 1;
    }
    for(int i=0;i<lost.size();i++){
        arr[lost[i]-1]--;
    }
    for(int i=0;i<reserve.size();i++){
        arr[reserve[i]-1]++;
    }
    for(int i=0;i<lost.size();i++){
        if(arr[lost[i]-1] != 0) continue;
        if(lost[i]-2>=0&&arr[lost[i]-2]>=2){ //왼
            arr[lost[i]-1]++;
            arr[lost[i]-2]--;
            continue;
        }
        if(lost[i]<n && arr[lost[i]]>=2){ //오
            arr[lost[i]-1]++;
            arr[lost[i]]--;
            continue;
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>=1)
            answer++;
    }
    return answer;
}
