#include <string>
#include <vector>
#include <math.h>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string s;
    int size = arr1.size();
    for(int i=0;i<size;i++){
        arr1[i] = arr1[i]|arr2[i];
    }
    int value = pow(2,n-1);
    for(int i=0;i<size;i++){
        s = "";
        for(int j=0;j<size;j++){
            if((arr1[i]>>(size-j-1)&1) == 1) s += "#";
            else s +=" ";
        }
        answer.push_back(s);
    }
    return answer;
}
