#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string s,temp="";
    int size = arr1.size();
    for(int i=0;i<size;i++){
        arr1[i] = arr1[i] | arr2[i];
        temp +=' ';
    }
    for(int i=0;i<size;i++){
        s = temp;
        for(int j=0;j<size;j++){
            if(arr1[i]>>j & 1) s[size-j-1] = '#';
        }
        answer.push_back(s);
    }
    return answer;
}
